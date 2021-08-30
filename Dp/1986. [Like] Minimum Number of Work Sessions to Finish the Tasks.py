# bitmask dp. np-complete.O(TN2^N)
class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        n = len(tasks)
        
        @lru_cache(None)
        def dfs(mask, x):
            if mask == (1<<n)-1: return 0
            res = int(1e9)
            for i in range(len(tasks)):
                if mask >> i & 1: continue
                if x >= tasks[i]:
                    res = min(res, dfs(mask | (1<<i), x - tasks[i]))
                res = min(res, 1 + dfs(mask | (1<<i), sessionTime - tasks[i]) )
            return res
        return dfs(0, 0)
      
# O(N2^N) super fast. just use pair to do that (numbers of session, accumulate time).
# impressive.
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        
        // numbers of session, last time
        vector<pair<int, int>> dp(1<<n);
        dp[0] = {1, 0};
        for(int S = 1; S < 1<<n; ++S){
            pair<int, int> best = {n+1, 0};
            for(int i = 0; i < n; ++i){
                if(S >> i & 1){
                    auto cur = dp[S ^ (1<<i)];
                    if(cur.second + tasks[i] <= sessionTime)
                        cur.second += tasks[i];
                    else
                        cur = {cur.first+1, tasks[i]};
                    best = min(best, cur);
                }
            }
            dp[S] = best;
        }
        
        return dp.back().first;
    }
};
