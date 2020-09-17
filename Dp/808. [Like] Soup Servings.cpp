// O(1). A nice observe is when N is very big the p = 0.99999...
// so can try and error to find a value bound.
// and tricky is take 25 as base. so that can reduce the space.

class Solution {
public:
    double dp[205][205];
    double dfs(int a, int b){
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1;
        if(b <= 0) return 0;
        if(dp[a][b] > 0) return dp[a][b];
        return dp[a][b] = 0.25*(dfs(a-4, b) + dfs(a-3, b-1) + dfs(a-2, b-2) + dfs(a-1, b-3));
    }
    double soupServings(int N) {
        N = (N+24)/25;
        if(N > 200) return 1.0;
        memset(dp, 0, sizeof dp);
        return dfs(N, N);
    }
};
