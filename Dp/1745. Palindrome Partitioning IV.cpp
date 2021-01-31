// Simple dp. O(N^2)
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for(int i = 0; i+1 < n; ++i) if(s[i] == s[i+1])
            dp[i][i+1] = 1;
        
        for(int i = 2; i < n; ++i){
            for(int j = 0; i+j < n; ++j){
                if(s[j] == s[i+j] && dp[j+1][i+j-1]){
                    dp[j][i+j] = 1;
                }
            }
        }
        
        for(int l = 0; l < n; ++l){
            for(int r = l+1; r < n; ++r){
                int leftl = 0, leftr = l;
                int midl = l+1, midr = r-1; 
                int rightl = r, rightr = n-1; 
                if(dp[leftl][leftr] && dp[midl][midr] && dp[rightl][rightr]){
                    return 1;
                }
            }
        }
        return false;
    }
};
