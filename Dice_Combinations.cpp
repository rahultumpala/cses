#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
#define dbg(x) cout << #x << " = " << x << endl

int dp[1000005];
int MOD = 1e9 + 7;

int32_t main() {
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    forn(i, 1, 7) dp[i] = 1;
    forn(sum, 2, n + 1) {
        forn(dice, 1, 7) {
            if (sum - dice < 0)
                continue;
            dp[sum] =  (dp[sum] + dp[sum - dice]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}
