#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)

/*
1 <= i <= N
1 <= v <= M since numbers in the array can range from 1 to M
dp[i][v] = number of ways to fill the array up to index i, if array[i] = v.

dp[0][v] = 1 for all 1 <= v <= M if array[0] = 0

dp[0][v] = 1 when array[0] == v, only one array matches this description ,i.e when array[i] = v

since difference between adjacent number is atmost 1

dp[i][v] = sum of no. of arrays that match the description
    when the previous number is v-1 or v or v+1

dp[i][v] = dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]

*/
int MOD = 1e9 + 7;
int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    forn(i, 0, n) cin >> ar[i];
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    if (ar[0] == 0)
        forn(i, 1, m + 1) dp[0][i] = 1;
    else
        dp[0][ar[0]] = 1;

    forn(i, 1, n) {
        forn(v, 1, m + 1) {
            if (ar[i] == 0 || ar[i] == v){
                (dp[i][v] += dp[i-1][v-1]) %= MOD;
                (dp[i][v] += dp[i-1][v]) %= MOD;
                (dp[i][v] += dp[i-1][v+1]) %= MOD;
            }
        }
    }
    int count = 0;
    forn(i, 1, m + 1) {
        (count += dp[n - 1][i]) %= MOD;
    }
    cout << count;
    return 0;
}
