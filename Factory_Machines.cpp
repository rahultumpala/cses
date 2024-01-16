#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long
#define forn(i, k, e) for (int i = k; i < e; i++)

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> times(n);
    forn(i, 0, n) {
        cin >> times[i];
    }
    sort(times.begin(), times.end());
    int lo = 0, hi = times[n - 1] * k;
    int time = hi;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) / 2);
        int count = 0;
        forn(i, 0, n) {
            count += mid / times[i];
        }
        if (count >= k) {
            time = mid;
            hi = mid - 1;
        } else
            lo = mid + 1;
    }
    cout << time << endl;
    return 0;
}