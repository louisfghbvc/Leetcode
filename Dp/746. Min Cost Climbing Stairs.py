# fib tweak. O(N)
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost) <= 2: return min(cost)
        
        @lru_cache(None)
        def dfs(i):
            if i <= 1: return 0
            return min(cost[i-1] + dfs(i-1), cost[i-2] + dfs(i-2))
        
        return dfs(len(cost))
