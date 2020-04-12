//O(N)
//0ms 6.1MB
//just think base. and iterative.
//not the math problem. cool...
class Solution {
public:
    int numOfWays(int n) {
        long a121 = 6, a123 = 6, b121, b123, mod = 1e9+7;
        for(int i = 1; i < n; ++i){
            b121 = (3*a121 + 2*a123) % mod;
            b123 = (2*a121 + 2*a123) % mod;
            a121 = b121;
            a123 = b123;
        }
        return (a121+a123)%mod;;
    }
};
/*
a121 => 3*b121 + 2*b123;
a123 => 2*b121 + 2*b123
*/
