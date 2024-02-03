#include <bits/stdc++.h>

using namespace std;

#define forn(i,k,e) for(int i = k; i < e; i++)

/*
count number of ways to get sum = x by using n coins
(one coin can be used more than once)

count(x) = 1 if x == coin value
count(x) = 0 if x < coin value
count(x) = sum(count(x-coin)) for every coin
*/

const int MOD = 1e9 + 7;
int _count[1000001];

int32_t main()
{
	memset(_count, 0, sizeof(_count));
	int n, sum;
	cin >> n >> sum;
	vector<int> coins(n);
	forn(i, 0, n) cin >> coins[i];
	sort(coins.begin(), coins.end());
	_count[0] = 1; // set _count[0] = 1 to add 1 when coin value == sum
	forn(x, 0, sum + 1) {
		for (int coin : coins) {
			if (coin > x) break;
			_count[x] =  (_count[x] +  _count[x - coin]) % MOD;
		}
	}
	cout << _count[sum];
}

