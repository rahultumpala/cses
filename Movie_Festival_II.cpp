#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
typedef pair<int, int> pii;

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies;
    forn(i, 0, n) {
        int a, b;
        cin >> a >> b;
        movies.push_back({b, a}); // insert end time, start time
    }
    sort(movies.begin(), movies.end()); // sort based on end time
    int count = 0;
    multiset<int> end; // store end times of cur movies
    forn(i, 0, k) end.insert(0);
    forn(i, 0, n) {
        pii cur = movies[i];
        // find if any movie ends when/before current movie starts
        auto iter = end.upper_bound(cur.second);
        if(iter == end.begin()) continue; 
        iter--;
        end.erase(iter);
        end.insert(cur.first); // store end time of cur movie;
        count++;
    }
    cout << count;
    return 0;
}
