// O(n^2). every one can be root
// and divide to i-1, n-i
class Solution {
public:
    unordered_map<int, int> memo;
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        if(memo[n]) return memo[n];
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            sum += numTrees(i-1)*numTrees(n-i);
        }
        return memo[n] = sum;
    }
};

// O(n^2). iterative. more fast
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
