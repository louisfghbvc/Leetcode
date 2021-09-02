# BFS. but slow, but we can use symmetric to x -> abs(x), y -> abs(y)
# then go bfs.




# Solution2
# DP + DFS + Top Down. No matter what x, y is
# symmetric we can (x+y) == 0, get 0
# and x+y == 2, get 2, x+y == 1, get 3. just the base case
# and get the final ans.
# use this transition. and we want (x, y) -> (0, 0)
# O(|X|*|Y|)
class Solution:
    # since it is symmetric. so we don't really simulate the process
    # and just calculate the minimum answer.
    def minKnightMoves(self, x: int, y: int) -> int:
        @lru_cache(None)
        def dfs(x: int, y: int):
            x, y = abs(x), abs(y)
            if x + y == 0: return 0
            elif x + y == 2: return 2
            return 1 + min(dfs(x - 2, y - 1), dfs(x - 1, y - 2))
        return dfs(x, y)
      
# Math Formula,
