/*

Sort vertices in decreasing order of their indegree

for each node in the sorted list
 - mark current node as visited
 - dfs thru the neighbors if not already visited
 - set parent[next] = current
 - stop if neighbor is same as start and nodes count in the path is atleast 3 (start -> X -> start = round trip)
 - set parent[start] = current if start is neighbor to current and the current path is a valid round trip

 : if there is a valid round trip :
    - begin from parent[start] until start is reached
    - print in reverse order

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> adj;
    map<int, int> indegree;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    vector<pair<int, int>> indegree_sorted;
    for (auto [node, in] : indegree) {
        indegree_sorted.push_back({in, node});
    }

    sort(indegree_sorted.begin(), indegree_sorted.end(), greater<pair<int, int>>());

    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    int start = -1;

    auto dfs = [&](auto &&self, int node, int cnt) -> pair<int, int> {
        visited[node] = true;

        for (int next : adj[node]) {

            if (next == start) {
                parent[next] = node;
                return {start, cnt + 1};
            }

            if (visited[next]) {
                continue;
            }

            parent[next] = node;

            auto [node_in_cycle, node_cnt] = self(self, next, cnt + 1);

            if (node_in_cycle == start)
                return {node_in_cycle, node_cnt};
        }

        return {-1, -1};
    };

    for (auto [_indegree, node] : indegree_sorted) {
        if (visited[node])
            continue;

        start = node;

        auto [v, node_cnt] = dfs(dfs, node, 1);
        if (v == start && node_cnt >= 3) {
            vector<int> cycle_path;

            for (v;; v = parent[v]) {
                cycle_path.push_back(v);
                if (v == start && cycle_path.size() > 1)
                    break;
            }

            cout << node_cnt << endl;

            for (auto iter = cycle_path.rbegin(); iter != cycle_path.rend(); iter++)
                cout << *iter << " ";

            return 0;
        }
    }

    cout << "IMPOSSIBLE";
}