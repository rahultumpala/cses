#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
/*
Given an (a x b) rectangle, your task is to cut it into squares.
On each move you can select a rectangle and cut it into two rectangles
in such a way that all side lengths remain integers.
What is the minimum possible number of moves?

cuts = 0 when a == b
cuts = b-1 when a == 1
cuts = a-1 when b == 1

else

2 choices -
 1. cut horizontally (1 cut)
   - now we have 2 rectangles of (len, b), (a - len, b)
 2. cut vertically (1 cut)
   - now we have 2 rectangles of (a, len), (a, b-len)
return min of each choice at every combination
*/

int memo[501][501];

int cut(int a, int b) {
    if (memo[a][b] != -1)
        return memo[a][b];
    if (a == b)
        return memo[a][b] = 0;
    if (a > b)
        swap(a, b);
    if (a == 1) {
        memo[a][b] = b - 1;
        memo[b][a] = b - 1;
        return b - 1;
    }
    int ans = INT_MAX;
    for (int len = 1; len < b; len++) {
        ans = min(ans, 1 + cut(a, len) + cut(a, b - len));
    }
    for (int len = 1; len < a; len++) {
        ans = min(ans, 1 + cut(len, b) + cut(a - len, b));
    }
    memo[a][b] = ans;
    memo[b][a] = ans;
    return ans;
}

int32_t main() {
    memset(memo, -1, sizeof(memo));
    int a, b;
    cin >> a >> b;
    cout << cut(a, b) << endl;
}
