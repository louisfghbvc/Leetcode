// O(N^2). string dp.

class Solution {
public:
    
    int n;
    string s;
    vector<int> dp;
    vector<vector<bool>> isP;
    
    int dfs(int i){ // numbers of palindrome
        if(i >= s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int res = 1 + dfs(i+1);
        for(int j = i+1; j < n; ++j){
            if(s[j] == s[i]){
                // s[i+1:j-1] is palindrome in O(1)
                if(i+1 == j || isP[i+1][j-1]){
                    res = min(res, 1 + dfs(j+1));
                }
            }
        }
        return dp[i] = res;
    }
    
    int minCut(string s) {
        this->s = s;
        n = s.size();
        dp = vector<int>(n, -1);
        isP = vector<vector<bool>> (n, vector<bool>(n));
        
        for(int i = 0; i < n; ++i) isP[i][i] = 1;
        for(int i = 1; i < n; ++i) if(s[i] == s[i-1]) isP[i-1][i] = 1;
        for(int i = 2; i < n; ++i){ // length
            for(int j = 0; j + i < n; ++j){
                if(s[j] == s[j + i] && isP[j+1][i+j-1])
                    isP[j][j+i] = 1;
            }
        }
        
        return dfs(0) - 1;
    }
};
