#include <bits/stdc++.h>

using namespace std;

#define int long long
/*
	for each digit in the number subtract the digit and find min. steps required to make it zero
	count(n) = 0, n == 0
	count(n) = 1, 1 <= n <= 9
	count(n) = min( count(n - x) ), for every digit x in decimal representation of n
*/

int32_t main()
{
	int num;
	cin >> num;
	int count[num+1];
	memset(count, 0, sizeof(count));
	for(int n = 1; n <= num; n++){
		set<int> digits;
		count[n] = INT_MAX;
		int copy = n;
		while(copy > 0) {
			digits.insert(copy % 10);
			copy /= 10;
		}
		for(int x : digits){
			count[n] = min(count[n], 1 + count[n-x]);
		}
	}
	cout << count[num];
	return 0;
}

