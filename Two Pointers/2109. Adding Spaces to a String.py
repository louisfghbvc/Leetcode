# O(N + M), space O(M)
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        res = []
        
        # use hashset and check if in spaces add it
        spaces = set(spaces)
        for i in range(len(s)):
            if i in spaces:
                res += ' ',
            res += s[i],
        
        return ''.join(res)
        
# use two pointers
# just forward spaces pointer, then no need set
# O(N + M), space O(1)
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        res = []
        
        j = 0
        for i, x in enumerate(s):
            if j < len(spaces) and i == spaces[j]:
                j += 1
                res += ' ',
            res += x,
        
        return ''.join(res)
