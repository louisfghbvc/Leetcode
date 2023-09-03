class Solution {
public:
    
    vector<long> fac, ifac;
    long mod = 1e9+7;
    
    void init() {
        fac.assign(27, 1);
        ifac.assign(27, 1);
        for (int i = 1; i <= 26; ++i)
            fac[i] = fac[i-1] * i % mod;
        ifac[26] = fpow(fac[26], mod-2);
        for (int i = 25; i >= 0; --i)
            ifac[i] = ifac[i+1] * (i+1) % mod;
    }
    
    long C(long m, long n) {
        return (fac[m] * ifac[n]) % mod * ifac[m-n] % mod;
    }
    
    long fpow(long a, long b) {
        long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            b >>= 1;
            a = a*a%mod;
        }
        return res;
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        // goal: find the number of maximum length k subsequence of sum is maximum
        
        // 1 <= s <= 2*10^5
        // 1 <= k <= s.size()
        
        // idea:
        // choose k distinct element
        // sort by fre
        
        // k > distinct ?
        unordered_set<char> st(s.begin(), s.end());
        if (k > st.size()) return 0;
        
        // fre[c] * fre[b], ....
        // fre[c] * fre[a], 
        
        // choose maximum distinct largest, 
        // x _ _ _, 4 fre[2]
        //   1 2 3, Clen_k * k! * pow(fre[v], k) 
        init();
        vector<int> cnt(26);
        for (char c: s)
            cnt[c-'a']++;
        vector<int> tmp;
        for (int i = 0; i < 26; ++i)
            tmp.push_back(cnt[i]);
        sort(tmp.rbegin(), tmp.rend());
        
        int m = tmp.size();
        
        long pre = 1;
        long ans = 0;
        for (int i = 0, j; i < m; i = j) {
            j = i;
            while (j < m && tmp[j] == tmp[i]) j++;
            int len = j-i;
            if (len >= k) { // last part can choose these element
                // C len choose k
                ans = ans + pre * C(len, k) % mod * fpow(tmp[i], k) % mod;
                ans %= mod;
                break;
            }
            else {
                for (int l = i; l < j; ++l)
                    pre = (pre * tmp[l]) % mod;
                k -= len;
            }
        }
        
        return ans;
    }
};
