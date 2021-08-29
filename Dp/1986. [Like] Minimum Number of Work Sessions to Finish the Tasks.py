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
      
# O(3^N)
