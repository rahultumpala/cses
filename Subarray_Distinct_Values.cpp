#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
double eps = 1e-12;
#define forn(i, k, e) for (ll i = k; i < e; i++)
#define fat(x) for (auto &it : x)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define pr_vec(x)                 \
    fat(x) { cout << it << " "; } \
    cout << ln
#define read_vec(x) \
    fat(x) { cin >> it; }
#define pb push_back
#define fi first
#define se second
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define kamozeyyyy
#define wr(x) cout << x << ln

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    forn(i, 0, n) cin >> nums[i];
    map<int, int> m;
    int cnt = 0;
    int l = 0;
    forn(i, 0, n) {
        m[nums[i]]++;
        while (m.size() > k) {
            int l_num = nums[l++];
            m[l_num]--;
            if (m[l_num] == 0)
                m.erase(l_num);
        }
        cnt += (i - l + 1);
    }
    cout << cnt << endl;
    return 0;
}
