class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        
        # dp[i]: maximum from this to end
        # dp[i] = max(dp[i+1], points[i] + dp[i + brainpower + 1]]
        
        @lru_cache(None)
        def dfs(i):
            if i >= len(questions):
                return 0
            return max(dfs(i+1), questions[i][0] + dfs(i + questions[i][1] + 1))
        
        return dfs(1)
