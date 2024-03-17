#include <bits/stdc++.h>

using namespace std;
/*
Copied from Codeforces
I just cant solve it rn - will revisit later
I need time to internalize this concept

The trick here is to see that since the sum of the two players' scores is the sum of the input list, player 1 tries to maximize score1−score2
, while player 2 tries to minimize it.

dp[l][r] = differencescore1−score2
if considering the game played only on interval [l, r].

If the interval contains only one element (l = r), then the first player must take that element. So dp[i][i] = x[i].

Otherwise, player 1 can choose to take the first element or the last element. If he takes the first element, he gets x[l] points, and we are left with the interval [l+1,r], but with player 2 starting. score1−score2
 on interval [l+1,r] is just dp[l+1][r] if player 1 starts. Since player 2 starts, it is -dp[l+1][r]. Thus, the difference of scores will be x[l]-dp[l+1][r] if player 1 chooses the first element. Similarly, it will be x[r]-dp[l][r-1] if he chooses the last element. He always chooses the maximum of those, so dp[l][r] = max(x[l]-dp[l+1][r], x[r]-dp[l][r-1]).

In this problem dp[l][r] depends on dp[l+1][r], and therefore we need to compute larger l before smaller l. We do it by looping through l from high to low. r still needs to go from low to high, since we depend only on smaller r (dp[l][r] depends on dp[l][r-1]). Note that in all the other problems in this editorial, dp only depends on smaller indices (like dp[x] depending on dp[x-v], or dp[i][x] depending on dp[i-1][x]), which means looping through indices in increasing order is correct.

We can reconstruct the score of player 1 as the mean of, the sum of all input values, and score1−score2
 */

int32_t main() {
    int n;
    cin >> n;
    vector<long long> ar(n);
    long long sum = 0;
    for (auto &it : ar) {
        cin >> it;
        sum += it;
    }
    long long dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int l = n - 1; l >= 0; l--) {
        for (int r = 0; r < n; r++) {
            if (l == r)
                dp[l][r] = ar[l];
            else {
                dp[l][r] = max(ar[l] - dp[l + 1][r], ar[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (sum + dp[0][n - 1]) / 2 << endl;
    return 0;
}