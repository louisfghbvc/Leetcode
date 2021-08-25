# Two Pointers. O(sqrt(c))
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        l, r = 0, int(sqrt(c))
        while l <= r:
            val = l*l + r*r
            if val == c: return True
            elif val < c: l += 1
            else: r -= 1
        return False
        
# Enumerate all candiate <= sqrt(c) O(sqrt(c) * logx)
