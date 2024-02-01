#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i, k, e) for (int i = k; i < e; i++)
#define dbg(x) cout << #x << " = " << x << endl
/*
goal = maximize the sum of elements in a window
when storing prefix sums : optimal to subtract prefix sum smallest in the window(sorted set)
storing of prefix sums in window implies we are always calculating subarray sum
in contrast to storing of values in window(here we may not be calculating sum of a contiguous sub array)
*/
int32_t main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n + 1);
    forn(i, 1, n + 1) cin >> nums[i];
    vector<int> pref(n + 1, 0);
    forn(i, 1, n + 1) pref[i] += nums[i] + pref[i - 1];
    int ans = LLONG_MIN;
    set<pair<int, int>> window;
    int left = 0;
    int start = 0;
    forn(i, a, n + 1) {
        window.insert({pref[left], left++});
        ans = max(ans, pref[i] - window.begin()->first);
        if (i - start >= b)
            window.erase({pref[start], start++});
    }
    cout << ans;
    return 0;
}