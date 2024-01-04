#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define fat(x) for (auto &it : x)
#define read_vec(x) \
    fat(x) { cin >> it; }
#define all(x) (x).begin(), (x).end()

int32_t main() {
    int n, x;
    cin >> n >> x;
    vi ar(n);
    read_vec(ar);
    sort(all(ar));
    int ans = 0;
    int l = 0, r = n - 1;
    int cnt = 0;
    while (cnt < n) {
        if (ar[l] + ar[r] <= x) {
            l++;
            r--;
            cnt++;
        } else if (ar[r] <= x) {
            r--;
        } else if (ar[l] <= x) {
            l++;
        } else {
            break;
        }
        ans++;
        cnt++;
    }
    cout << ans << endl;
    return 0;
}