// O(N). Two pass. Not optimal
// First get [l, r] array.
// then use array sliding window again.
// if overlap, maintain min.
// or if small then one, replace one.

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<pair<int, int>> res;
        int l = 0;
        int sum = 0;
        for(int r = 0; r < arr.size(); ++r){
            sum += arr[r];
            while(l < r && sum > target) sum -= arr[l++];
            if(sum == target){
                res.push_back({l, r});
            }
        }
        int mn = INT_MAX;
        if(res.size() == 0) return -1;
        pair<int, int> ll = res[0];
        for(int i = 1; i < res.size(); ++i){
            if((res[i].first >= ll.first && res[i].first <= ll.second) || (res[i].second >= ll.first && res[i].second <= ll.second)){
                if(ll.second-ll.first > res[i].second-res[i].first){
                    ll = res[i];
                }
                continue;
            }
            mn = min(mn, (res[i].second-res[i].first)+1 + (ll.second-ll.first)+1);
            if(ll.second-ll.first > res[i].second-res[i].first){
                ll = res[i];
            }
        }
        if(mn == INT_MAX) return -1;
        return mn;
    }
};

// Solution2.
