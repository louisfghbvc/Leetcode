class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<int> validity;
        for(int i = 0; i < m; ++i){
            int cur = 0;
            for(int j = 0; j < n; ++j){
                cur = cur * 2 + (seats[i][j] == '.'); 
            }
            validity.push_back(cur);
        }
        vector<vector<int>> dp(m + 1, vector<int>(1<<n, -1));
        dp[0][0] = 0;
        for(int i = 1; i <= m; ++i){
            int valid = validity[i - 1];
            for(int j = 0; j < (1<<n); ++j){
                //j is subset of valid and j not have adj
                if((j & valid) == j && !(j & (j >> 1))){
                    for(int k = 0; k < (1<<n); ++k){
                        // not upper left, not upper right and not -1
                        if(!((j>>1) & k) && !(j & (k>>1)) && dp[i - 1][k] != -1){
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + __builtin_popcount(j));
                        }
                    }
                }
            }
        }
        return *max_element(dp[m].begin(), dp[m].end());
    }
};
