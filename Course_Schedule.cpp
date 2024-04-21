#include <bits/stdc++.h>

using namespace std;

/*
Topological sort using Kahn's Algorithm
*/

int main() {
    int n, m;
    cin >> n >> m;

    map<int, vector<int>> adj;
    vector<int> indegree(n + 1, 0);

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    if (q.empty()) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> order;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for (int next : adj[cur]) {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    if (order.size() != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int v : order) {
        cout << v << " ";
    }

    return 0;
}