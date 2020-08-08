// Dp. O(Nsqrt(N)).
// if i-factor can false. i win

class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N + 1];
        memset(dp, false, sizeof dp);
        for(int i = 2; i <= N; ++i){
            for(int j = 1; j * j <= i; ++j){
                if(i % j == 0 && !dp[i - j])
                    dp[i] = true;
            }
        }
        return dp[N];
    }
};
