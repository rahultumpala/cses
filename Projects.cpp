#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> t3;

/*
same as leetcode 435. Maximise non overlapping intervals

sort based on end time.

find the max reward that can be achieved upto start day (prevMaxReward)

add current reward to prevMaxReward and store the max in ans

set max reward achievable upto end day in ans & in map.

repeat by searching in map

 -- dp[i] = max reward that can be achieved upto day i --
*/

signed main(){
	int n;
	cin >> n;
	vector<t3> projects;
	for(int i = 0; i < n; i++){
		int a,b,r;
		cin >> a >> b >> r;
		projects.push_back({a,b,r});
	}
	
	sort(projects.begin(), projects.end(), [](t3 &x, t3 &y){
		auto [a1, b1, r1] = x;
		auto [a2, b2, r2] = y;
		return b1 < b2;
	});

	// dp[i] = max reward that can be achieved upto day i
	
	map<int, long long> dp;
	dp[0] = 0;

	long long ans = 0;

	for(int i = 0; i < n; i++){
		auto [a, b, r] = projects[i];
		
		auto iter = dp.lower_bound(a);

		long long prevMaxReward = prev(iter)->second;
		
		dp[b] = max(dp[b], r + prevMaxReward);

		ans = max(ans, r + prevMaxReward);

		dp[b] = ans;
	}
	
	cout << ans << endl;
}