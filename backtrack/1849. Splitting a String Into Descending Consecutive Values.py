class Solution:
    def splitString(self, s: str) -> bool:
        n = len(s)
        
        def dfs(lt, i):
            if i == n:
                if len(lt) < 2: return False
                return True
            t = ''
            for j in range(i, n):
                t += s[j]
                if lt and int(lt[-1]) - int(t) != 1: continue
                if dfs(lt + [t], j+1): return True
            return False
        return dfs([], 0)
