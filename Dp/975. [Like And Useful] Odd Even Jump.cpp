// O(NlogN). Dp from backward. very trick and impressive.
// since u need to find the closest j. so backward to do that.

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<bool, bool>> dp(n);
        dp[n-1] = {true, true};
        
        map<int, int> mp;
        int res = 1;
        for(int i = n-1; i >= 0; --i){
            auto p = mp.lower_bound(arr[i]);
            auto p2 = mp.upper_bound(arr[i]);
            if(p != mp.end()){
                dp[i].first = dp[p->second].second;
                res += dp[i].first;
            }
            if(p2 != mp.begin()){
                dp[i].second = dp[prev(p2)->second].first;
            }
            mp[arr[i]] = i;
        }
        return res;
    }
};
