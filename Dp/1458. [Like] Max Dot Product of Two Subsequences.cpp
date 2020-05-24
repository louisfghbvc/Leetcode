// LCS trick.... just keep two seq same length. and calculate max product.
// Just a classic problem.
// not choose sequence1 or not choose sequence2 or neither
// neither case check left-top is neg or add it.
// Next time I will solve it.
// I use O(N^4) TLE. cheers.

static int p = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 1;
}();
class Solution {
public:
    int dp[505][505];
    int maxDotProduct(vector<int>& n1, vector<int>& n2) {
        int n = n1.size(), m = n2.size();
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; ++j)
                dp[i][j] = INT_MIN;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
                dp[i][j] = max(dp[i][j], max(dp[i-1][j-1], 0)+n1[i-1]*n2[j-1]);
            }
        }
        return dp[n][m];
    }
};
