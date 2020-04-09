//0ms 5.9MB
class Solution {
public:
    int memo[35] = {};
    int fib(int N) {
        if(N <= 1) return N;
        if(memo[N]) return memo[N];
        return memo[N] = fib(N-1)+fib(N-2);
    }
};
