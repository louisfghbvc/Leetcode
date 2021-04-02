// Choose or not choose. dp and memo m, n
// O(NMN)

class Solution {
public:
    int dp[605][105][105];
    int dfs(vector<string>& arr, int i, int r0, int r1){
        if(i >= arr.size()) return 0;
        if(dp[i][r0][r1] != -1) return dp[i][r0][r1];
        int res = dfs(arr, i+1, r0, r1);
        int pr0 = r0, pr1 = r1;
        for(auto c: arr[i]){
            if(c == '0') r0--;
            else r1--;
        }
        if(r0 >= 0 && r1 >= 0) res = max(res, 1+dfs(arr, i+1, r0, r1));
        return dp[i][pr0][pr1] = res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof dp);
        return dfs(strs, 0, m, n);
    }
};

// Knapsack. O(NMN). Bottom up.
// put from backward.

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for(auto &s: strs){
            int one = 0, zero = 0;
            for(char c: s){
                if(c == '1') one++;
                else zero++;
            }
            
            for(int i = m; i >= zero; --i){
                for(int j = n; j >= one; --j){
                    dp[i][j] = max(dp[i][j], dp[i-zero][j-one]+1);
                }
            }
            
        }
        
        return dp[m][n];
    }
};
