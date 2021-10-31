# awesome, gen all case.
# in digit, so smart, just forward and use difference to check if possible
# Time complextiy O(NMC). C = +-1000

class Solution:
    def possiblyEquals(self, s1: str, s2: str) -> bool:
        n, m = len(s1), len(s2)
        
        # generate all possible digit sum
        def gen(s: str):
            ans = [int(s)]
            if len(s) == 2:
                ans.append(int(s[0]) + int(s[1]))
            elif len(s) == 3:
                ans.append(int(s[0]) + int(s[1:]))
                ans.append(int(s[0:2]) + int(s[2:]))
                ans.append(int(s[0]) + int(s[1]) + int(s[2]))
            return ans
        
        @lru_cache(None)
        def dfs(i, j, diff):
            if i == n and j == m: return diff == 0
            if i < n and s1[i].isdigit():
                ii = i
                while ii < n and s1[ii].isdigit(): ii += 1
                for x in gen(s1[i:ii]):
                    if dfs(ii, j, diff+x): return True
            elif j < m and s2[j].isdigit():
                jj = j
                while jj < m and s2[jj].isdigit(): jj += 1
                for x in gen(s2[j:jj]):
                    if dfs(i, jj, diff-x): return True
            elif diff == 0:
                if i == n or j == m or s1[i] != s2[j]: return False
                return dfs(i+1, j+1, diff)
            elif diff < 0:
                if i == n: return False
                return dfs(i+1, j, diff+1)
            else:
                if j == m: return False
                return dfs(i, j+1, diff-1)
            return False
        
        return dfs(0, 0, 0)
