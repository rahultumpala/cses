#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
#define dbg(x) cout << #x << " = " << x << endl

/*
    create another 2d array paths
    paths[i][j] = no. of ways to reach (i,j) from (i-1,j) and (i, j-1)
     (since only right and down moves are allowed)
*/

int MOD = 1e9 + 7;

int32_t main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    forn(i, 0, n) cin >> grid[i];

    int paths[n][n];
    memset(paths, 0, sizeof(paths));

    if(grid[0][0] == '*'){
        cout << 0; // since you're not allowed to step into a cell with *
        return 0;
    }
    paths[0][0] = 1; // set to 1 to start counting paths from 1

    // set values of first row
    forn(i, 1, n)
    if ( grid[0][i] == '*') break;
    else paths[0][i] = paths[0][i - 1];

    // set values of first column
    forn(i, 1, n)
    if ( grid[i][0] == '*') break;
    else paths[i][0] = paths[i - 1][0];

    forn(i, 1, n) {
        forn(j, 1, n) {
            if (grid[i][j] == '*') continue;

            if(grid[i-1][j] != '*') 
                paths[i][j] = (paths[i-1][j]) % MOD;

            if(grid[i][j-1] != '*') 
                paths[i][j] = (paths[i][j] + paths[i][j-1]) % MOD;            
        }
    }
    cout << paths[n-1][n-1];
    return 0;
}
