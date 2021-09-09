# Four direction dp O(N^2 + M)
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        g = [[1 for _ in range(n)] for _ in range(n)]
        for i, j in mines:
            g[i][j] = 0
        
        dp1 = [[0 for _ in range(n)] for _ in range(n)]
        dp2 = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            # going right
            for j in range(n):
                dp1[i][j] = dp1[i][j-1] + 1 if j and g[i][j] else g[i][j]
            # goint left
            for j in range(n-1, -1, -1):
                dp2[i][j] = dp2[i][j+1] + 1 if j+1<n and g[i][j] else g[i][j]
        
        dp3 = [[0 for _ in range(n)] for _ in range(n)]
        dp4 = [[0 for _ in range(n)] for _ in range(n)]
        for j in range(n):
            # going down
            for i in range(n):
                dp3[i][j] = dp3[i-1][j] + 1 if i and g[i][j] else g[i][j]
            # going up
            for i in range(n-1, -1, -1):
                dp4[i][j] = dp4[i+1][j] + 1 if i+1<n and g[i][j] else g[i][j]
        
        return max(min(dp1[i][j], dp2[i][j], dp3[i][j], dp4[i][j]) for i in range(n) for j in range(n))

# Space optimal only use one dp grid. just simple prefix
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        g = [[1 for _ in range(n)] for _ in range(n)]
        for i, j in mines:
            g[i][j] = 0
        ans = 0
        
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            # going right
            cnt = 0
            for j in range(n):
                cnt = 0 if not g[i][j] else cnt+1
                dp[i][j] = cnt
            # goint left
            cnt = 0
            for j in range(n-1, -1, -1):
                cnt = 0 if not g[i][j] else cnt+1
                if cnt < dp[i][j]: dp[i][j] = cnt
        
        for j in range(n):
            # going down
            cnt = 0
            for i in range(n):
                cnt = 0 if not g[i][j] else cnt+1
                if cnt < dp[i][j]: dp[i][j] = cnt
            # going up
            cnt = 0
            for i in range(n-1, -1, -1):
                cnt = 0 if not g[i][j] else cnt+1
                if cnt < dp[i][j]: dp[i][j] = cnt
                if dp[i][j] > ans: ans = dp[i][j]
        
        return ans
