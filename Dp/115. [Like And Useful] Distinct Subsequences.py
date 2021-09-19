# Top down + Memo is all you need.
# Think easier. How to compare and move pointer. 

class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        
        @lru_cache(None)
        def dfs(i, j):
            # base case
            if j == len(t): return 1
            if i == len(s): return 0
            if s[i] == t[j]: # same, can move j or not move
                return dfs(i+1, j+1) + dfs(i+1, j)
            return dfs(i+1, j)
        
        return dfs(0, 0)
      
      
# Bottom up, base on recursive formula.
