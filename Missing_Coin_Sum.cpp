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
    vector<int> coins(n);
    read_vec(coins);
    sort(all(coins));
    int min_sum = 1;
    for (int coin : coins) {
        if (coin <= min_sum)
            min_sum += coin;
        else {
            cout << min_sum << endl;
            return 0;
        }
    }
    cout << min_sum << endl;
    return 0;
}