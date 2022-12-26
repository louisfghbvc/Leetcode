class Solution {
public:
    
    int mod = 1e9+7;
    
    long fpow(long a, long b) {
        long res = 1;
        while (b) {
            if (b & 1) res = res*a%mod;
            b >>= 1;
            a = a*a%mod;
        }
        return res;
    }
    
    int countAnagrams(string s) {
        // goal: count the distinct anagrams
        // idea: math, split the word each word
        
        // modinv, factor
        
        // too = 3!/2!1! = 3
        // hot = 3!/1!1!1! = 6
        
        int n = s.size();
        
        vector<long> fac(n+1, 1), ifac(n+1, 1);
        
        for (int i = 1; i <= n; ++i)
            fac[i] = fac[i-1]*i%mod;
        
        ifac[n] = fpow(fac[n], mod-2); // mod inverse;
        for (int i = n-1; i >= 0; --i)
            ifac[i] = ifac[i+1]*(i+1)%mod;
        
        stringstream ss(s);
        
        long ans = 1;
        while (ss >> s) {
            n = s.size();
            
            
            int fre[26] = {};
            for (char c: s)
                fre[c-'a']++;
            
            ans *= fac[n];
            ans %= mod;
            
            for (int i = 0; i < 26; ++i)
                ans = ans * ifac[fre[i]] % mod;
        }
        
        return ans;
    }
};
