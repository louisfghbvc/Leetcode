// Top down dp. O(NM).

class Solution {
public:
    vector<vector<int>> dp;
    string s1, s2, s3;
    
    // s1 index, s2 index
    int dfs(int i, int j){
        if(i+j >= s3.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = false;
        if(i < s1.size() && s1[i] == s3[i+j]){
            res = res | dfs(i+1, j);
        }
        if(j < s2.size() && s2[j] == s3[i+j]){
            res = res | dfs(i, j+1);
        }
        return dp[i][j] = res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        dp = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, -1));
        return dfs(0, 0);
    }
};
