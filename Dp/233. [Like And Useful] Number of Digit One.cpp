// Digit dp. top down, easy to understand. cnt is atmost 10.
// O((logN)^3). hard to think

class Solution {
public:
    string s;
    int dp[10][10][2];
    int dfs(int i, int cnt, bool flag){ // flag = 0, means bound is current bit.
        if(i == s.size()) return cnt;
        int &res = dp[i][cnt][flag];
        if(res != -1) return res;
        res = 0;
        int bound = (!flag) ? s[i]-'0' : 9;
        for(int k = 0; k <= bound; ++k){
            int ncnt = cnt + (k == 1);
            bool nflag = flag || k != bound;
            res += dfs(i+1, ncnt, nflag);
        }
        return res;
    }
    
    int countDigitOne(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, 0);
    }
};
