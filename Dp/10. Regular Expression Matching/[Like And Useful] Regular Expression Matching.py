# hard to thought.
# always think about state machine...
# time: O(N^2). space: O(N^2)
'''
  base if p is end. check s is end or not.
  then check j char.
  if j+1 char == '*'. then can have two case: ignore, or j ok continue use.
  else just still go i+1, j+1.
'''

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        @lru_cache(None)
        def dfs(i, j):
            if j == len(p): return i == len(s)
            first = i < len(s) and p[j] in {s[i], '.'}
            if j+1 < len(p) and p[j+1] == '*':
                ans = dfs(i, j+2) or first and dfs(i+1, j)
            else:
                ans = first and dfs(i+1, j+1)
            return ans
        
        return dfs(0, 0)
