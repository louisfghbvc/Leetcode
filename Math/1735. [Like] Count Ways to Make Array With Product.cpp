// Think it as star and bar. and think prime.
// say 6 = 2x3. if size = 2
// so [2, 1], [1, 2] 
//    [3, 1], [1, 3]
// ways = 2x2 = 4.
// if 2x2x2, if size = 3, how?.
// think it as 5 positions. say 2_22_
// then = C(3 + 3-1, 3-1). 5 pos choose 2 to split them.


// O(Nsqrt(N)).

class Solution {
public:
    long fac[10020], inv_fac[10020];
    const int mod = 1e9+7, N = 1e4+15;
    long fpow(int a, int b, int m){
        long res = 1;
        while(b){
            if(b&1) res = res*a%m;
            a = (long)a*a%m;
            b >>= 1;
        }
        return res;
    }
    void init(){
        fac[0] = 1;
        for(int i = 1; i <= N; ++i) 
            fac[i] = fac[i-1] * i % mod;
        
        inv_fac[N] = fpow(fac[N], mod-2, mod);
        // 1/(n-1)! = 1/n! * n
        for(int i = N; i >= 1; --i)
            inv_fac[i-1] = inv_fac[i] * i % mod;
    }
    long comb(int n, int m){
        return fac[n] * (inv_fac[n-m] * inv_fac[m] % mod) % mod;
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        init();
        vector<int> res;
        for(auto&q: queries){
            int n = q[0], k = q[1];
            long ans = 1;
            for(int p = 2; p * p <= k; p++){
                int c = 0;
                while(k%p == 0){
                    k /= p;
                    c++;
                }
                // c at most log(1e4).
                if(c) ans = comb(c+n-1, n-1) * ans % mod; 
            }
            if(k > 1) ans = ans * n % mod;
            res.push_back(ans);
        }
        return res;
    }
};
