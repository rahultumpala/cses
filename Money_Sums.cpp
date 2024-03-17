#include <bits/stdc++.h>

using namespace std;

#define fat(x) for (auto &it : x)
#define pr_vec(x)                 \
    fat(x) { cout << it << " "; } \
    cout << endl
#define read_vec(x) \
    fat(x) { cin >> it; }
#define all(x) (x).begin(), (x).end()

/*
naive way =
either choose or don't choose current num
TC = O(2^N)
SC = O(2^N) stack frames when recursing

sums can range from coins[i] to sum(coins) when coins is sorted in asc order
states = idx, rolling sum
let dp[i][s] >= 1 if it is possible to create sum = s using coins upto index i
dp[0][coins[0]] = 1

recurrence relation =

dp[i][s] = 1 if(s == coins[i])
           don't choose            choose
dp[i][s] =  dp[i-1][s]    +   dp[i-1][s-coins[i]] if(s > coins[i])

if(dp[i][s] >= 1) add this "s" to the set of sums

TC = O(N * sum(coins))
SC = O(N * sum(coins))
*/
int32_t main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    read_vec(coins);
    sort(all(coins));

    int sum = 0;
    for (int coin : coins)
        sum += coin;

    int dp[n + 1][sum + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][coins[0]] = 1;

    set<int> sums;
    // when n == 1  
    sums.insert(coins[0]);

    for (int i = 1; i < n; i++) {
        for (int s = 0; s <= sum; s++) {

            if (s == coins[i])
                dp[i][s] = 1;

            dp[i][s] += dp[i - 1][s];

            if (s >= coins[i])
                dp[i][s] += dp[i - 1][s - coins[i]];

            if (dp[i][s] >= 1) {
                sums.insert(s);
            }
        }
    }

    cout << sums.size() << endl;
    pr_vec(sums);

    return 0;
}
