// Classic Like bag.
// O(Nsqrt(N)).
// dp[i] true only if any i-(k in sq)... is false

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> sq;
        for(int i = 1; i*i <= n; ++i){
            sq.push_back(i*i);
        }
        vector<bool> dp(n+1);
        dp[1] = true;
        for(int i = 1; i <= n; ++i){
            for(auto &k: sq){
                if(i < k) break;
                if(!dp[i-k]) dp[i] = 1;
            }
        }
        return dp[n];
    } 
};
