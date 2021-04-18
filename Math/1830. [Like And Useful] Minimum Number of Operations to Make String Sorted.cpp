// After hashing. careful duplicate. just use combination.

class Solution {
public:
    const int mod = 1e9+7;
    
    long fpow(long a, long b){
        long res = 1;
        while(b){
            if(b&1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }
    
    int makeStringSorted(string s) {
        vector<int> fre(26);
        for(char c: s) fre[c- 'a']++;
        
        int n = s.size();
        vector<long> fac(n+1);
        vector<long> invfac(n+1);
        fac[0] = invfac[0] = 1;
        for(long i = 1; i <= n; ++i){
            fac[i] = (fac[i-1] * i) % mod;
            invfac[i] = fpow(fac[i], mod-2);
        }
        
        long res = 0;
        for(int i = 0; i < n; ++i){
            long cnt = 0; 
            long fresum = 0;
            long duplicate = 1;
            for(int k = 0; k < 26; ++k){
                if(k < s[i] - 'a') fresum += fre[k];
                duplicate = (duplicate * invfac[fre[k]]) % mod;
            }
            res = res + (fresum * fac[n-1-i] % mod) * duplicate % mod;
            res %= mod;
            fre[s[i] - 'a']--;
        }
        
        return res;
    }
};
