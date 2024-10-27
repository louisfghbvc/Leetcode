class Solution {
public:
    
    using mat = vector<vector<long>>;
    int mod = 1e9+7;
    
    mat mul(mat&a, mat& b) {
        int n = a.size();
        mat res(n, vector<long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    res[i][j] += a[i][k] * b[k][j] % mod;
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    }
    
    mat fpow(mat& a, long b) {
        int n = a.size();
        mat res(n, vector<long>(n, 0)); // I
        for (int i = 0; i < n; ++i)
            res[i][i] = 1;
        while (b) {
            if (b & 1) res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }
    
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // goal: find the length after trac
        
        // idea:
        // when nums[i] = 1, is trivial
        // consider nums[i] > 1
        
        // brute force => t * 26
        // can we using matrix exp?
        
        
        // fn   [1 1] [fn-1]
        // fn-1 [ ]   [fn-2]
        
        vector<int> fre(26);
        for (char c: s)
            fre[c-'a']++;
        
        mat conv(26, vector<long>(26));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                // cout << (i+j)%26 << ' ' << i << endl;
                conv[(i+j)%26][i]++;
            }
        }
        conv = fpow(conv, t);
        
        vector<long> res(26);
        long ans = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans += (conv[i][j] * fre[j]) % mod;
                ans %= mod;
            }
        }
        return ans;
    }
};
