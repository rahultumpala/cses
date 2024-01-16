#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define dbg(x) cout << #x << " " << x << endl;
/*
use an ordered set to find an element by its index
skip k elements and fetch (k+1)th element in each iteration
*/
int32_t main() {
    int n, k;
    cin >> n >> k;
    ordered_set st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    int start = k + 1;
    while (st.size() > 0) {
        vector<int> values;
        int last = 0;
        for (int i = start; i <= (int)st.size(); i += k + 1) {
            int val = *st.find_by_order(i - 1);
            cout << val << " ";
            values.push_back(val);
            last = i;
        }
        start = (k + 1) - (st.size() - last);
        for (int v : values)
            st.erase(v);
        if (st.size() == 0)
            break;
        if (start % st.size() == 0)
            start = st.size();
        else
            start %= st.size();
    }
    return 0;
}