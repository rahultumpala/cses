#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)

/*
find max no. of pages(N) for given money X

since one book cannot be used more than once,
sort the books in asc. order of price of book

state vars := money, index of current book

state transition := 

dp[i][j] = 0 when i < price of book
dp[i][j] = max(dp[i][j-1] , pages + dp[i-price][j-1])

// dp[i][j-1] = max pages you can purchase upto the previous book, with money = i
// dp[i-price][j-1] = max pages you can purchase upto previous book, with money = i - price of cur book

*/

typedef pair<int, int> pii;

vector<pii> books;
int X, N;

int32_t main() {
    cin >> N >> X;
    books.resize(N);
    forn(i, 0, N) cin >> books[i].first;
    forn(i, 0, N) cin >> books[i].second;
    sort(books.begin(), books.end());
    vector<vector<int>> dp(X + 1, vector<int>(N + 1, 0));
    forn(i, 1, X + 1) {
        forn(j, 1, N + 1) {
            int price = books[j - 1].first;
            int pages = books[j - 1].second;
            if (i < price)
                dp[i][j] = 0;
            else {
                dp[i][j] = max(pages + dp[i - price][j - 1], dp[i][j-1]);
            }
        }
    }

    cout << dp[X][N];
    return 0;
}
