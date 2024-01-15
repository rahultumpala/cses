#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> t3;

int main() {
    int n;
    cin >> n;
    vector<t3> ranges;
    multiset<int> x;
    multiset<int> y;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        ranges.push_back({s, e, i});
        x.insert(e);
        y.insert(e);
    }
    sort(ranges.begin(), ranges.end(), [](t3 a, t3 b) {
        auto [s1, e1, i] = a;
        auto [s2, e2, j] = b;
        if (s1 == s2)
            return e1 > e2;
        return s1 < s2;
    });

    vector<int> contains(n);
    for (auto [s, e, i] : ranges) {
        x.erase(x.find(e));
        contains[i] = x.upper_bound(e) != x.begin();
    }
    for (int i : contains)
        cout << i << " ";
    cout << endl;

    sort(ranges.begin(), ranges.end(), [](t3 a, t3 b) {
        auto [s1, e1, i] = a;
        auto [s2, e2, j] = b;
        if (s1 == s2)
            return e1 < e2;
        return s1 > s2;
    });

    vector<int> contained(n);
    for (auto [s, e, i] : ranges) {
        y.erase(y.find(e));
        contained[i] = y.lower_bound(e) != y.end();
    }
    for (int i : contained)
        cout << i << " ";
    cout << endl;

    return 0;
}