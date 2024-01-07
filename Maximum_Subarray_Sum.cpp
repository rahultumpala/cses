#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
#define forn(i, k, e) for (int i = k; i < e; i++)
#define fat(x) for (auto &it : x)
#define read_vec(x) \
    fat(x) { cin >> it; }

int32_t main() {
    int n;
    cin >> n;
    vi nums(n);
    read_vec(nums);
    int running_sum = 0, max_sum = LLONG_MIN;
    forn(i, 0, n) {
        running_sum += nums[i];
        max_sum = max(running_sum, max_sum);
        if (running_sum < 0)
            running_sum = 0;
    }
    cout << max_sum << endl;
    return 0;
}