// O(N^2) Dp[i][diff] : differnce end with i
// So dp[i] from dp[j]. but here we add 1, cuz we can contribute the len 2.
// like say nums[i] = 8, [4, 6], nums[j] = 6, so we add [4, 6, 8], [6, 8]

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long, int>> cnt(n);
        
        
        long res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                long diff = (long)nums[i] - (long)nums[j];
                
                int sum = 0;
                // sum is use from j
                if(cnt[j].count(diff)) sum = cnt[j][diff];
                
                // update cur i
                cnt[i][diff] += sum + 1; 
                
                res += sum;
            }
        }
        
        return res;
    }
};
