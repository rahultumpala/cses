#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int, int> pi;
#define forn(i, k, e) for (int i = k; i < e; i++)
#define fat(x) for (auto &it : x)

typedef pair<int, int> pii;

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    if(k == 1){
        for(int i: nums) {
             cout << i << " ";
        }
    }else if (k == 2){
        for(int i = 0; i < n - 1; i++){
            cout << min(nums[i], nums[i+1]) << " ";
        }
    }else {
        // store value,index
        set<pii> left, right;
        left.insert({nums[0], 0});
        int l_boundary = 0;
        for(int i = 1; i < n; i++){
            pii median = *left.rbegin();
            int num = nums[i];
            if(num < median.first){
                left.insert({num, i});
            }else{
                right.insert({num, i});
            }
            while(left.size() < right.size()){
                left.insert(*right.begin());
                right.erase(*right.begin());
            }
            while(right.size() < left.size() - 1){
                right.insert(*left.rbegin());
                left.erase(*left.rbegin());
            }
            if(i + 1 >= k){
                cout << (*left.rbegin()).first << " ";
                pii window_outside = {nums[l_boundary], l_boundary};
                if(left.find(window_outside) != left.end()){
                    left.erase(window_outside);
                }else {
                    right.erase(window_outside);
                }
                l_boundary++;
            }
        }
    }
    return 0;
}
