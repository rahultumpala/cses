#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fat(x) for (auto &it : x)
#define read_vec(x) \
    fat(x) { cin >> it; }
#define all(x) (x).begin(), (x).end()

int32_t main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    read_vec(ar);
    sort(all(ar));
    int half = (n / 2);
    int med = n % 2 != 0 ? ar[half] : (ar[half] + ar[half - 1]) / 2;
    int cost = 0;
    fat(ar) cost += abs(med - it);
    cout << cost << endl;
    return 0;
}