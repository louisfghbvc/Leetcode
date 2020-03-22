//Hard to think. like 0/1 backpack. but not choose adjcent. tricky make circle to two linear
//dp[i][j], from index 0~i, take j items, max value
//O(N^2) 32ms 12.5MB
class Solution {
public:
    int solve(const vector<int>& num){
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(n/3+1, INT_MIN));
        
        dp[0][0] = 0; dp[0][1] = num[0];
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= n/3; ++j){
                dp[i][j] = dp[i-1][j];
                if(j == 1) dp[i][j] = max(dp[i][j], num[i]);
                if(i >= 2 && j >= 1) dp[i][j] = max(dp[i][j], dp[i-2][j-1] + num[i]);
            }
        }
        return dp[n-1][n/3];
    }
    int maxSizeSlices(vector<int>& slices) {
        vector<int> tmp = slices;
        tmp[0] = slices.back() = INT_MIN; // no take first or back both
        return max(solve(tmp), solve(slices));
    }
};
