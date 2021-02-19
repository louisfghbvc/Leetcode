// Similar to LC. 5 regular expression match.
// but this is more simple I think
// backtracking all case. remember the edge case.
// O(NM).

class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(string &s, string &p, int i, int j){
        if(j == p.size()) return i == s.size();
        if(dp[i][j] != -1) return dp[i][j];
        bool res = false;
        if(i < s.size() && s[i] == p[j]){
            res = dfs(s, p, i+1, j+1);
        }
        else if(i < s.size() && p[j] == '?'){
            res = dfs(s, p, i+1, j+1);
        }
        else if(p[j] == '*'){
            res = dfs(s, p, i, j+1);
            if(i < s.size()) res |= dfs(s, p, i+1, j);
        }
        return dp[i][j] = res;
    }
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size()+1, vector<int>(p.size(), -1));
        return dfs(s, p, 0, 0);
    }
};
