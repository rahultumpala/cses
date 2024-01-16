#include <bits/stdc++.h>

using namespace std;

#define forn(i, k, e) for (int i = k; i < e; i++)
typedef pair<int, int> pi;

/*
sort based on entry times
put residents in buckets
for each new resident find a bucket whose exit time is less than current entry time
set the bucket exit time = current exit time

store bucket exit times in min_heap
*/

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v;
    forn(i, 0, n) {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e, i});
    }
    sort(v.begin(), v.end(), [](auto x, auto y) {
        auto [s1, e1, i] = x;
        auto [s2, e2, j] = y;
        if (s1 != s2)
            return s1 < s2;
        return e1 > e2;
    });

    auto comp = [](pi x, pi y) { return x.first >= y.first; };
    priority_queue<pi, vector<pi>, decltype(comp)> pq(comp);
    map<int, vector<int>> buckets;
    vector<int> rooms(n, 0);

    for (auto [s, e, i] : v) {
        if (pq.size() > 0 && pq.top().first < s) {
            int room = pq.top().second;
            rooms[i] = room;
            pq.pop();
            pq.push({e, room});
        } else {
            int room = pq.size() + 1;
            rooms[i] = room;
            pq.push({e, room});
        }
    }

    cout << pq.size() << endl;
    for (int room : rooms)
        cout << room << " ";
    return 0;
}
