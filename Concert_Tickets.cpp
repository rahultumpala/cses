#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;
    map<int, int> tickets;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        tickets[t]++;
    }
    for (int i = 0; i < m; i++) {
        int customer_price;
        cin >> customer_price;
        if (tickets.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        auto paid = tickets.lower_bound(customer_price);
        if (paid == tickets.begin() && paid->first > customer_price)
            cout << -1 << endl;
        else {
            if (paid == tickets.end() || paid->first > customer_price)
                paid--;
            cout << paid->first << endl;
            tickets[paid->first]--;
            if (tickets[paid->first] == 0)
                tickets.erase(paid->first);
        }
    }
    return 0;
}
