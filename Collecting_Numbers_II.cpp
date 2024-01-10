#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
#define fat(x) for (auto &it : x)
#define wr(x) cout << x << endl

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1, 0);
    vector<int> pos(n + 2, 0);
    pos[n + 1] = INT_MAX;
    forn(i, 1, n + 1) {
        cin >> nums[i];
        pos[nums[i]] = i;
    }
    int rounds = 1;
    forn(i, 0, n) if (pos[i] > pos[i + 1]) rounds++;
    forn(i, 0, m) {
        int a, b;
        cin >> a >> b;
        int ia = nums[a], ib = nums[b];
        if (ia > ib)
            swap(ia, ib);
        rounds -= (pos[ia] > pos[ia + 1]) + (pos[ib] > pos[ib + 1]) + (pos[ia - 1] > pos[ia]);
        // if condn here to avoid subtracting twice when ia, ib are adjacent
        if (ib - ia > 1)
            rounds -= (pos[ib - 1] > pos[ib]);
        swap(pos[ia], pos[ib]);
        swap(nums[a], nums[b]);
        rounds += (pos[ia] > pos[ia + 1]) + (pos[ib] > pos[ib + 1]) + (pos[ia - 1] > pos[ia]);
        // if condn here to avoid adding twice when ia, ib are adjacent
        if (ib - ia > 1)
            rounds += (pos[ib - 1] > pos[ib]);
        wr(rounds);
    }
    return 0;
}