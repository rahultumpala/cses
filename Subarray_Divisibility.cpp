#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < (int)e; i++)
#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    forn(i, 0, n) cin >> nums[i];
    int sum = 0;
    int count = 0;
    map<int, int> m;
    m[0] = 1;
    forn(i, 0, n) {
        sum += nums[i];
        int d = sum % n;
        count += m[d];
        if (d < 0) {
            count += m[d + n];
            m[n + d]++;
        } else {
            m[d]++;
        }
    }
    cout << count << endl;
    return 0;
}
