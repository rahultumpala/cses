#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
#define fat(x) for (auto &it : x)
#define dbg(x) cout << #x << " = " << x << endl
#define read_vec(x) \
    fat(x) { cin >> it; }

int32_t main() {
    int n;
    cin >> n;
    vector<int> songs(n);
    read_vec(songs);
    set<int> playlist;
    int l = 0, count = 0;
    forn(i, 0, n) {
        while (playlist.find(songs[i]) != playlist.end()) {
            playlist.erase(songs[l++]);
        }
        playlist.insert(songs[i]);
        count = max(count, (int)playlist.size());
    }
    cout << count << endl;
    return 0;
}