// O(NlogN). Trick only sort 1. if same and other is descending. think [2,3], [5,4], [6,4], [6,7]
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        
        vector<int> arr;
        for(auto &en: envelopes){
            auto p = lower_bound(arr.begin(), arr.end(), en[1]);
            if(p == arr.end()) arr.push_back(en[1]);
            else *p = en[1];
        }
        return arr.size();
    }
};


// O(N^2). simple lis

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        
        vector<int> dp(n, 1);
        int mx = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
