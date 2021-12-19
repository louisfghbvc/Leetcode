# simple dp
# O(N), O(1) space

class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        # use a param to record the maxiumum conitinous descent
        
        mx, res = 0, 0
        prev = -1
        for x in prices:
            if prev == x+1:
                mx += 1
            else:
                mx = 1
            res += mx
            prev = x
            
        return res
