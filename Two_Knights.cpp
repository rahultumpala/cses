#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i, k, e) for (int i = k; i < e; i++)

int32_t main() {
    int n;
    cin >> n;
    forn(k, 1, n + 1) {
        int cnt = (k * k) * (k * k - 1) / 2; // choose two positions in K x K matrix = Nc2(K*K)
        int threeTwoMatrices = (k - 2) * (k - 1);
        int twoThreeMatrices = (k - 1) * (k - 2);
        // each 2x3, 3x2 matrix has 2 attack positions
        /*
            K_ or _K
            __    __
            _K    K_
        */
        cnt = cnt - (2 * threeTwoMatrices) - (2 * twoThreeMatrices);
        cout << cnt << endl;
    }
    return 0;
}
