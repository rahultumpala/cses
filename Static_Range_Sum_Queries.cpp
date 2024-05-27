#include<bits/stdc++.h>

using namespace std;

signed main() {
	int n, q;
	cin >> n >> q;
	vector<long long> nums(n + 1);
	nums[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		nums[i] += nums[i-1];
	}
	while(q--){
		int a,b;
		cin >> a >> b;
		cout << nums[b] - nums[a-1] << endl;
	}
}