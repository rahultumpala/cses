#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i, k, e) for (int i = k; i < e; i++)

int32_t main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    forn(i, 0, n) cin >> nums[i];
    map<int, int> pref;
    pref[0] = 1;
    int count = 0;
    int sum = 0, r = 0;
    while (r < n) {
        sum += nums[r++];
        int d = sum - x;
        count += pref[d];
        pref[sum]++;
    }
    cout << count << endl;
}
