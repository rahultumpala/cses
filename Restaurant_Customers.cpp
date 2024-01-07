#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
#define forn(i, k, e) for (int i = k; i < e; i++)
#define fat(x) for (auto &it : x)
#define dbg(x) cout << #x << " = " << x << endl

int32_t main() {
    int n;
    cin >> n;
    vector<pi> times(n);
    fat(times) cin >> it.first >> it.second;
    priority_queue<int, vector<int>, greater<int>> heap;
    sort(times.begin(), times.end());
    heap.push(times[0].second);
    int mc = 1;
    forn(i, 1, n) {
        pi cur = times[i];
        while (!heap.empty() && cur.first > heap.top()) {
            heap.pop();
        }
        heap.push(cur.second);
        mc = max(mc, (int)heap.size());
    }
    cout << mc << endl;
    return 0;
}