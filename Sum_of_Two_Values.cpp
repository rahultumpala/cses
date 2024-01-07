#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
#define fat(x) for (auto &it : x)
#define read_vec(x) \
    fat(x) { cin >> it; }
#define all(x) (x).begin(), (x).end()

int32_t main() {
    int n, x;
    cin >> n >> x;
    vector<int> ar(n);
    read_vec(ar);
    map<int, int> m;
    forn(i, 0, n) {
        int req = x - ar[i];
        if (m.find(req) != m.end()) {
            cout << m[req] + 1 << " " << i + 1 << endl;
            return 0;
        }
        m[ar[i]] = i;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}