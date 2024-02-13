#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
/*
goal := convert string a into string b
find the shortest path from a to b through a sequence of edits with each operation cost = 1
if substitution cost = 2 then it is levenshtein distance

let dp[i,j] = edit distance btwn substrings a[1..i], b[1..j]
so dp[i,1] = i & dp[1,j] = j since insert op is performed
recurrence relation :=

dp[i,j] = min{
            dp[i-1,j] + cost of insert,
            dp[i, j-1] + cost of delete,
            dp[i-1,j-1] +
                    cost of substitute if a[i] != b[j]
                    0 if a[i] == b[j]
            }
final ans := dp[n,m]
*/

int32_t main() {
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    forn(i, 1, n + 1) dp[i][0] = i;
    forn(j, 1, m + 1) dp[0][j] = j;
    forn(i, 1, n + 1) {
        forn(j, 1, m + 1) {
            dp[i][j] = min({dp[i - 1][j] + 1,
                            dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]) });
        }
    }
    cout << dp[n][m];
    return 0;
}
