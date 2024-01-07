#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
#define forn(i, k, e) for (int i = k; i < e; i++)
#define fat(x) for (auto &it : x)
#define all(x) (x).begin(), (x).end()

int32_t main() {
    int n;
    cin >> n;
    vector<pi> times(n);
    fat(times) cin >> it.first >> it.second;
    sort(all(times));
    vector<pi> merged{times[0]};
    forn(i, 1, n) {
        pi prev = merged[merged.size() - 1];
        pi cur = times[i];
        if (cur.first < prev.second) {
            prev.first = max(cur.first, prev.first);
            prev.second = min(cur.second, prev.second);
            merged[merged.size() - 1] = prev;
        } else {
            merged.push_back(cur);
        }
    }
    cout << merged.size() << endl;
    return 0;
}