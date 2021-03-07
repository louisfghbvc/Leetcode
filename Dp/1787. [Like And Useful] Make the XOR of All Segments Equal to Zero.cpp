// Hard to think Dp. O(NK).
// Observe, A[i] = A[i+k]. A[i+1] = A[i+i+k] ...
// So 2 Case.
// Case 1 is all XOR value = prev_mx.
// Since always can get from previous max, doesn't consider operations, only consider numbers u can get.
// Case 2 from current value try to XOR all mask to extand dp, if value is zero u can not use.

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<vector<int>> mir(k, vector<int>(1024, 0));
        for(int i = 0; i < nums.size(); ++i)
            mir[i%k][nums[i]]++;
        
        vector<int> dp(1024, -1e7);
        dp[0] = 0;
        for(auto &row: mir){
            int prev_mx = *max_element(dp.begin(), dp.end());
            vector<int> ndp(1024, prev_mx); 
            for(int i = 0; i < 1024; ++i){
                if(row[i]){
                    for(int j = 0; j < 1024; ++j){
                        ndp[i^j] = max(ndp[i^j], row[i] + dp[j]);
                    }
                }
            }
            dp = ndp;
        }
        
        return nums.size() - dp[0];
    }
};
