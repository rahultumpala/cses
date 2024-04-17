/*
 start = room 1
 end   = room n

 goal is to maximise score
 don't visit a room when already visited with higher score

 algorithm:
 Shortest Path Faster Algorithm - similar to bellman-ford

 Ans will be -1 when there is a positive score cycle in the path from 1 to N
 Cycle can be detected when a room is visited more than N times.
 When a room is part of a positive score cycle - add it to a set

 DFS from room N in the reverse direction towards room 1

 If you visit a room that is part of the positive score cycle set
 then ans will be -1. because this cycle can lead to Infinite score on path to room N

 Else ans will be score[N]
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, long long> pil;

signed main() {
    int n, m;
    cin >> n >> m;

    vector<long long> score(n + 1, LLONG_MIN);
    map<int, vector<int>> reverse_routes;
    map<int, vector<pil>> tunnels;
    vector<int> visit_cnt(n + 1, 0);
    vector<bool> inQueue(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        tunnels[a].push_back({b, x});
        reverse_routes[b].push_back(a);
    }

    // store {room, score}
    queue<int> q;
    q.push(1);

    // base case
    score[1] = 0;

    set<int> cycleNodes;

    while (!q.empty()) {
        int room = q.front();
        q.pop();
        inQueue[room] = false;
        // printf("%d %lld\n", room, room_score);

        for (pil next : tunnels[room]) {
            int next_room = next.first;
            long long new_score = score[room] + next.second;
            if (score[next_room] < new_score) {
                score[next_room] = new_score;
                if (!inQueue[next_room]) {
                    inQueue[next_room] = 1;

                    visit_cnt[next_room]++;

                    if (visit_cnt[room] > n) {
                        cycleNodes.insert(room);
                    } else {
                        q.push(next_room);
                    }
                }
            }
        }
    }

    bool more = false;

    vector<int> visited(n + 1, 0);
    auto dfs = [&](auto &&self, int room) {
        visited[room]++;
        if (cycleNodes.find(room) != cycleNodes.end()) {
            more = 1;
            return;
        }
        for (int next : reverse_routes[room]) {
            if (visited[next] == 0)
                self(self, next);
        }
    };
    dfs(dfs, n);

    cout << (more ? -1 : score[n]) << endl;
}