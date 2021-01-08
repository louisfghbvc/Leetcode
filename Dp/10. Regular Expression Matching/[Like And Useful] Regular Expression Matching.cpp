// Top-down is very simple.
// so base case is j == pattern.size, check i == string.size
// and first check i==j or j is '.'
// then 2 case. if p[j+1] == '*'.
// we can delete then dfs(i, j+2) or we can first (i+1, j).
// 
// O(N^2)

class Solution {
public:
    int dp[35][35];
    string s, p;
    
    bool dfs(int i, int j){
        if(j == p.size()) return i == s.size();
        if(dp[i][j] != -1) return dp[i][j];
        bool res = false;
        bool first = i < s.size() && (p[j] == '.' | p[j] == s[i]);
        if(j + 1 < p.size() && p[j+1] == '*')
            res = dfs(i, j+2) | (first && dfs(i+1, j));
        else
            res = first && dfs(i+1, j+1);
        return dp[i][j] = res;
    }
    
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof dp);
        this->s = s, this->p = p;
        return dfs(0, 0);
    }
};
