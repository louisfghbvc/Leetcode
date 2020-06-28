// Magic Bit Mask. O(3^N)
// Simulate all case. and prune.
// pre to calculate when study j, need study pre[j] first
// and nxt is next can study.
// i means now already study what.
// so nxt &= i, because nxt impossible study again same lesson.
// and submask if submask <= k, dp can come from it or not

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> pre(n);
        for(auto &e: dependencies){
            e[0]--, e[1]--;
            pre[e[1]] |= (1<<e[0]);
        }
        
        vector<int>dp(1<<n, n);
        dp[0] = 0;
        
        for(int i = 0; i < (1<<n) ; ++i){
            if(dp[i] == n) continue;
            int nxt = 0;
            for(int j = 0; j < n; ++j){
                if((i & pre[j]) == pre[j]) nxt |= (1<<j);
            }
            nxt &= ~i;
            for(int s = nxt; s; s = (s-1)&nxt){
                if(__builtin_popcount(s) <= k){
                    dp[i | s] = min(dp[i | s], dp[i]+1);    
                }
            }
            
        }
        
        return dp.back();
    }
};
