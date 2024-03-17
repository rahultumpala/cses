#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,k,e) for(int i = k; i < e; i++)

/*
	count(0) = INT_MAX
	count(sum) = INT_MAX if sum < smallest coin
	count(sum) = min( 1 + count(sum - coin) ) for every coin in coins
*/

int32_t main()
{
	int n, sum;
	cin >> n >> sum;
	vector<int> coins(n);
	forn(i, 0, n) cin >> coins[i];
	vector<int> cnt(sum + 1, INT_MAX);
	cnt[0] = 0;
	sort(coins.begin(), coins.end(), greater<int>());
	for(int s = 0; s <= sum; s++){
		for(int coin: coins){
			if(s < coin) continue;
			cnt[s] = min(cnt[s], 1 + cnt[s - coin]);
		}
	}
	if (cnt[sum] == INT_MAX)
		cout << -1;
	else cout << cnt[sum];
	return 0;
}