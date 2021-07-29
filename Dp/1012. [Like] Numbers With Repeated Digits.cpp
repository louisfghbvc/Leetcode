// Digit dp. O(logN2^N)
class Solution {
public:
    string s;
    int dp[10][1<<10][2][2];
    int dfs(int i, int mask = 0, bool flag = 0, bool lz = 1){
        if(i == s.size()) return 1;
        int &res = dp[i][mask][flag][lz];
        if(res != -1) return res;
        res = 0;
        int bound = !flag ? s[i] - '0' : 9;
        for(int d = 0; d <= bound; ++d){
            if((mask >> d & 1)) continue;
            bool nflag = flag || d != bound;
            int nmask = lz && d == 0 ? mask : mask | (1<<d);
            res += dfs(i+1, nmask, nflag, lz && d == 0);
        }
        return res;
    }
    
    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof dp);
        s = to_string(n);
        return n + 1 - dfs(0);
    }
};
