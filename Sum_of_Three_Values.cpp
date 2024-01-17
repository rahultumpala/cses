#include <bits/stdc++.h>

using namespace std;

#define int uint64_t
#define forn(i, k, e) for (int i = k; i < e; i++)
typedef pair<int, int> pii;

int search(vector<pii> &values, int start, int sum) {
    int count = 0;
    int l = start, r = values.size() - 1;
    while (l < r && r < values.size()) {
        int l_v = values[l].first;
        int r_v = values[r].first;
        if (l_v + r_v > sum)
            r--;
        if (l_v + r_v < sum)
            l++;
        if (l != r && l_v + r_v == sum) {
            count++;
            cout << values[start - 1].second << " " << values[l].second << " " << values[r].second << endl;
            l++;
            r--;
        }
    }
    return count;
}

int32_t main() {
    int n, x;
    cin >> n >> x;
    vector<pii> values(n);
    forn(i, 0, n) {
        cin >> values[i].first;
        values[i].second = i + 1;
    }
    sort(values.begin(), values.end());
    int count = 0;
    if (n >= 3)
        forn(i, 0, n - 2) {
            int cur_v = values[i].first;
            if (i == 0 || cur_v > values[i - 1].first)
                count += search(values, i + 1, x - cur_v);
        }
    if (count == 0)
        cout << "IMPOSSIBLE" << endl;
    return 0;
}