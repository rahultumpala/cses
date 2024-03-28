#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, k, e) for (int i = k; i < e; i++)
 
/*
let dp[i][s] = number of ways to form sum = s with first [1..i] numbers

        
dp[i][s] = dp[i-1][s] // do not choose current number

                    don't choose   +    choose
if(i <= s) dp[i][s] = dp[i-1][s]   +  dp[i-1][s-i]

*/
int32_t main() {
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if(sum % 2 != 0){
        cout << 0 << endl;
    }else {
        sum /= 2;
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        forn(i, 1, n + 1) {
            forn(s, 1, sum + 1) {
                dp[i][s] = dp[i-1][s];
                if (i <= s) {
                    dp[i][s] = (dp[i][s] + dp[i - 1][s - i]) % mod;
                }
            }
        }
        cout << dp[n][sum] << endl;
    }
}