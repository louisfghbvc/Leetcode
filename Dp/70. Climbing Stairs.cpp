class Solution {
public:
    vector<int> memo;
    int helper(int x){
        if(x <= 1) return x;
        if(memo[x]) return memo[x];
        return memo[x] = helper(x-1)+helper(x-2);
    }
    int climbStairs(int n) {
        memo.resize(n+2);
        return helper(n+1);
    }
};
