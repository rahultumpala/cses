#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i, k, e) for (int i = k; i < e; i++)

/*
3
2 8 3
K      8 2 3
J 2 3 3W 8 = 16
*/
int32_t main() {
    int n;
    cin >> n;
    vector<int> times(n);
    forn(i, 0, n) {
        cin >> times[i];
    }
    sort(times.begin(), times.end());
    int p = 0, k = 0;
    int l = 0, r = n - 1;
    while (times[r] > times[l]) {
        k += times[r];
        while (l < r && p < k) {
            p += times[l++];
        }
        if (l == r && p < k) {
            p += times[r] - p;
        }
        r--;
    }
    while (l < n)
        p += times[l++];
    while (r > -1)
        k += times[r--];

    if (n == 1)
        p += times[0];

    cout << max(p, k) << endl;
    return 0;
}