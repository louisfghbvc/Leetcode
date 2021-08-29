# string top down dp, but autually is advance, so no memo
# O(NM)
class Solution:
    def minWindow(self, s1: str, s2: str) -> str:
        start, L = -1, len(s1)+1
        def dfs(i, j):
            if j == len(s2): return i
            ind = s1.find(s2[j], i+1)
            return float('inf') if ind < 0 else dfs(ind, j+1)
                
        for i, c in enumerate(s1):
            if c == s2[0]:
                j = dfs(i, 1)
                if j - i + 1 < L:
                    L, start = j - i + 1, i
        
        return "" if start < 0 else s1[start : start+L]
