# LCS tweak. top down memo. O(NM)
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        # minimum cost, to make two string equal
        @lru_cache(None)
        def dfs(i, j):
            if i == len(s1) and j == len(s2): return 0
            # move s2
            if i == len(s1): return ord(s2[j]) + dfs(i, j+1)
            
            # move s1
            if j == len(s2): return ord(s1[i]) + dfs(i+1, j)
            
            # if same no cost
            if s1[i] == s2[j]:
                return dfs(i+1, j+1)
            else:
                # del s1[i] or s2[j]
                return min(ord(s1[i]) + dfs(i+1, j), ord(s2[j]) + dfs(i, j+1))
        
        return dfs(0, 0)

# Bottom up dp.
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        # add empty
        dp = [[0 for _ in range(len(s2)+1)] for _ in range(len(s1)+1)]
        
        for j in range(1, len(s2)+1):
            dp[0][j] += dp[0][j-1] + ord(s2[j-1])
        for i in range(1, len(s1)+1):
            dp[i][0] += dp[i-1][0] + ord(s1[i-1])
            
        
        for i in range(1, len(s1)+1):
            for j in range(1, len(s2)+1):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else: # move i or j.
                    dp[i][j] = min(dp[i-1][j] + ord(s1[i-1]), dp[i][j-1] + ord(s2[j-1]))
        
        return dp[-1][-1]
