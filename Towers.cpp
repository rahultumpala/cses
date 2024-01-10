#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)

int32_t main() {
    int n;
    cin >> n;
    vector<int> cubes;
    forn(i, 0, n) {
        int cube;
        cin >> cube;
        auto iter = upper_bound(cubes.begin(), cubes.end(), cube);
        if (iter == cubes.end()) {
            cubes.push_back(cube);
        } else {
            cubes[iter - cubes.begin()] = cube;
        }
    }
    cout << cubes.size() << endl;
    return 0;
}