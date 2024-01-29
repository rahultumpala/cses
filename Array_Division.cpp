#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long
#define forn(i, k, e) for (int i = k; i < e; i++)
#define dbg(x) cout << #x << " = " << x << endl

/*
sum of elements in the sub array should be atmost mid
smax = max of sum of a single subarray
ans = min(ans, smax) if count of subarrays <= k
*/

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    int hi = 0, lo = 0, ans = 1e11;
    forn(i, 0, n) {
        cin >> nums[i];
        hi += nums[i];
        lo = max(lo, nums[i]);
    }
    if (k == 1) {
        cout << hi << endl;
        return 0;
    }
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int cnt = 0;
        int sum = 0;
        int smax = 0;
        forn(i, 0, n) {
            int cur = nums[i];
            if (cur >= mid) {
                cnt++;
                if (sum > 0)
                    cnt++;
                smax = max({smax, cur, sum});
                sum = 0;
            } else
                sum += cur;
            if (sum >= mid) {
                cnt += 1;
                smax = max({smax, sum == mid ? mid : sum - cur});
                sum = sum == mid ? 0 : cur;
            }
            smax = max(smax, sum);
        }
        cnt += sum > 0;
        smax = max(smax, sum);
        if (cnt <= k) {
            ans = min(ans, smax);
            hi = mid - 1;
        } else
            lo = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
