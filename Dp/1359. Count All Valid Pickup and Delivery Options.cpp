//0ms 8.3MB
typedef long long LL;
class Solution {
public:
    const int mod = 1e9 + 7;
    LL sum(int n){
        return (1 + n) * n / 2;
    }
    int countOrders(int n) {
        int res = 1;
        for(int i = 0, c = 1; i < n; ++i, c += 2){
            res = (res%mod * sum(c)%mod) % mod;
        }
        return res;
    }
};
