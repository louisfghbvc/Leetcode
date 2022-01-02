# simple
# O(MN)

class Solution:
    def numberOfBeams(self, grid: List[str]) -> int:
        
        # count numbers of 1 each row
        pre, res = 0, 0
        for row in grid:
            one = row.count('1')
            res += pre * one
            if one: pre = one
        return res
