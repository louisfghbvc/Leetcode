// Digit dp, hard to think.
// f(n) is bitlen = n, number of not consective numbers.
// so f(n) = f(n-1)"0" + f(n-2)"01"
// From msb to lsb. 
// e.g 101100
// 1xxxxx add f(5)
// 101xxx add f(3)
// 1010xx add f(2)
// O(logN).

class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32);
        f[0] = 1, f[1] = 2;
        for(int i = 2; i < 31; ++i)
            f[i] += f[i-1] + f[i-2];
        
        int res = 0, prev_bit = 0;
        for(int i = 30; i >= 0; --i){
            if(n >> i & 1){ // bit is one
                res += f[i];
                if(prev_bit){ // consective one.
                    return res;
                }
                prev_bit = 1;
            }
            else{
                prev_bit = 0;
            }
        }
        
        return res + 1;
    }
};

// O(logN). Top down digit dp, easy to understand.
class Solution {
public:
    
    string s;
    int dp[32][2][2];
    int dfs(int i = 0, int prev = 0, bool flag = 0){
        if(i == s.size()) return 1;
        int &res = dp[i][prev][flag];
        if(res != -1) return res;
        res = 0;
        int bound = !flag ? s[i] - '0' : 1;
        for(int k = 0; k <= bound; ++k){
            if(prev && k) continue;
            bool nflag = flag || k!=bound;
            res += dfs(i+1, k, nflag);
        }
        return res;
    }
    
    int findIntegers(int n) {
        s = "";
        while(n){
            s += '0' + (n&1);
            n >>= 1;
        }
        reverse(s.begin(), s.end());
        memset(dp, -1, sizeof dp);
        return dfs();
    }
};
