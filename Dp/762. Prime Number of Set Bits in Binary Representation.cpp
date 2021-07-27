// Digit dp, Top down. O(logN).
class Solution {
public:
    const set<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    
    string s;
    int dp[32][32][2];
    int dfs(int i = 0, int cnt = 0, bool flag = 0){
        if(i == s.size()) return prime.count(cnt);
        int &res = dp[i][cnt][flag];
        if(res != -1) return res;
        res = 0;
        int bound = !flag ? s[i]-'0' : 1;
        for(int k = 0; k <= bound ; ++k){
            bool nflag = flag || k!=bound;
            res += dfs(i+1, cnt + k, nflag);
        }
        return res;
    }
    
    int solve(int x){
        memset(dp, -1, sizeof dp);
        s = "";
        while(x){
            s += '0' + (x&1);
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return dfs();
    }
    
    int countPrimeSetBits(int left, int right) {
        return solve(right) - solve(left - 1);
    }
};
