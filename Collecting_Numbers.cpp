#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
#define fat(x) for (auto &it : x)
#define read_vec(x) \
    fat(x) { cin >> it; }

int32_t main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    read_vec(ar);
    vector<int> pos(n + 1, 0);
    forn(i, 0, n) pos[ar[i]] = i;
    int rounds = 1;
    forn(i, 0, n) {
        if (pos[i] > pos[i + 1])
            rounds++;
    }
    cout << rounds << endl;
    return 0;
}