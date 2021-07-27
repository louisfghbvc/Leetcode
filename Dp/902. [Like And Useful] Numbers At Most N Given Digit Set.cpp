// Digit dp + math
// so first sum < length n possible.
// and from leftmost to right.
// compute. and if can not have same digit. no need to compute remain.

// e.g. 100. digits = {1, 3, 5}.
// so first compute. xx + x. 3^2 + 3^1
// and fix 1xx. and has same but no need to add.
// 10x. no and return.

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string N = to_string(n);
        int ds = digits.size(), ns = N.size();
        
        int res = 0;
        for(int i = 1; i < ns; ++i)
            res += pow(ds, i);
        
        for(int i = 0; i < ns; ++i){
            bool same = false;
            for(string &sd: digits){
                if(sd[0] < N[i])
                    res += pow(ds, ns - 1 - i);
                else if(sd[0] == N[i]) same = true;
            }
            if(!same) return res;
        }
        
        return res+1;
    }
};

// From msb. and use two flag. since there is no zero, so use leading zero.
// O(log(N))

class Solution {
public:
    
    string s;
    vector<string> digits;
    int dp[32][2][2];
    int dfs(int i = 0, bool flag = 0, bool lz = 1){
        if(i == s.size()) return !lz;
        int &res = dp[i][flag][lz];
        if(res != -1) return res;
        res = 0;
        int bound = !flag ? s[i] - '0' : 9;
        for(string &c: digits){
            if(c[0] - '0' > bound) continue;
            bool nflag = flag || (c[0] - '0' != bound);
            res += dfs(i+1, nflag, 0);
        }
        if(lz) // leading zero, always can put 9, and still lz
            res += dfs(i+1, 1, lz);
        return res;
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp, -1, sizeof dp);
        s = to_string(n);
        this->digits = digits;
        return dfs();
    }
};
