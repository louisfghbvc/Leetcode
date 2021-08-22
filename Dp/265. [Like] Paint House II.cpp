// Dp O(NK). O(k) space.

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        
        // go for each row
        vector<int> dp(k); // prev dp
        for(int i = 0; i < n; ++i){
            vector<int> ndp(k, 1e9); // cur dp
            
            // min from left, from right
            vector<int> prev = dp, suf = dp;
            for(int j = 1; j < k; ++j) 
                prev[j] = min(prev[j-1], prev[j]);
            for(int j = k-2; j >= 0; --j) 
                suf[j] = min(suf[j+1], suf[j]);
            
            // choose a color j
            for(int j = 0; j < k; ++j){
                if(j) ndp[j] = min(ndp[j], prev[j-1] + costs[i][j]);
                if(j != k-1) ndp[j] = min(ndp[j], suf[j+1] + costs[i][j]);
            }
            dp = move(ndp);
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
