#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i, k, e) for (int i = k; i < e; i++)

// time     6 10 20
// deadline 4 9 6
//  -2 -7 -30 = -39 // sort on time not on deadline
//  -2 -20 -27 = -49

int32_t main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    forn(i, 0, n) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int time = 0;
    int ans = 0;
    for (auto it : v) {
        time += it.first;
        ans += it.second - time;
    }
    cout << ans << endl;
    return 0;
}