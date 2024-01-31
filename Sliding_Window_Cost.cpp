#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int, int> pii;
#define forn(i, k, e) for (int i = k; i < e; i++)
#define fat(x) for (auto &it : x)
#define dbg(x) cout << #x << " = " << x << "\n"
#define pr_vec(x)                 \
    fat(x) { cout << it << " "; } \
    cout << ln

/*
Find the median: using heap
iterate through all elements in window and sum the diff btwn element & median - gives TLE? YES
*/

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    multiset<pii> left, right;
    int sumLeft = 0, sumRight = 0;
    int back = 0;
    left.insert({nums[0], 0});
    sumLeft = nums[0];
    if (k == 1)
        cout << 0 << " ";
    forn(i, 1, n) {
        int cur = nums[i];
        if (k == 1) {
            cout << 0 << " ";
            continue;
        } else if (k == 2) {
            cout << max(cur, nums[i - 1]) - min(cur, nums[i - 1]) << " ";
            continue;
        }
        pii cur_pair = {cur, i};
        if (cur <= left.rbegin()->first) {
            left.insert(cur_pair);
            sumLeft += cur;
        } else {
            right.insert(cur_pair);
            sumRight += cur;
        }
        // rebalancing of sets to store median in left.rbegin()
        while (right.size() > 0 && left.size() <= right.size()) {
            left.insert(*right.begin());
            sumLeft += right.begin()->first;
            sumRight -= right.begin()->first;
            right.erase(right.begin());
        }
        while (left.size() > right.size() + 1) {
            right.insert(*left.rbegin());
            sumRight += left.rbegin()->first;
            sumLeft -= left.rbegin()->first;
            left.erase(*left.rbegin());
        }

        if (i + 1 >= k) {
            int median = (*left.rbegin()).first;
            int cost = (median * left.size()) - sumLeft + sumRight - (median * right.size());
            cout << cost << " ";
        }

        if (i + 1 >= k) {
            if (left.find({nums[back], back}) != left.end()) {
                left.erase({nums[back], back});
                sumLeft -= nums[back];
            } else if (right.find({nums[back], back}) != right.end()) {
                sumRight -= nums[back];
                right.erase({nums[back], back});
            }
            back++;
        }
    }
    return 0;
}