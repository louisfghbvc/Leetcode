// space O(N), time O(N)
// dp[i] = dp[i/2] + isOdd(i)
// can also use __builtin_popcount. but dp is better

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        for(int i = 1; i <= num; ++i){
            if(i % 2 == 0)
                dp[i] = dp[i/2];
            else
                dp[i] = dp[i/2] + 1; 
        }
        return dp;
    }
};
