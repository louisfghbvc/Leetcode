// memo need to be global or memory limit.
// so just enum.
// the trick is the last char. and contan value.
// so each can delete or not delete

int dp[105][105][30][105];
class Solution {
public:
    string s;
    int dfs(int i, int k, int last, int con){
        if(k < 0) return 999999;
        if(i >= s.size()) return 0;
        if(dp[i][k][last][con] != -1) return dp[i][k][last][con];
        int res = 999999;
        res = min(res, dfs(i+1, k-1, last, con));
        if(s[i] - 'a' == last){
            int inc = (con == 1 || con == 9 || con == 99) ? 1 : 0;
            res = min(inc + dfs(i+1, k, last, con + 1), res);
        }
        else{
            res = min(1 + dfs(i+1, k, s[i]-'a', 1), res);
        }
        return dp[i][k][last][con] = res;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        this->s = s;
        memset(dp, -1, sizeof dp);
        return dfs(0, k, 27, 0);
    }
};
