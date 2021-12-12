# maintain two array, each is like increasin, decreasing
# prefix, suffix
# and just enumerate the index.
# O(N)

class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        
        # go through from left,right building increasing value
        left = [0] * n
        for i in range(1, n):
            if security[i] >= security[i-1]:
                left[i] = left[i-1] + 1
        right = [0] * n
        for i in range(n-2, -1, -1):
            if security[i] >= security[i+1]:
                right[i] = right[i+1] + 1
        
        # easy to check all seq
        
        res = []
        for i in range(n):
            if i+2*time >= n: break
            if right[i] >= time and left[i+2*time] >= time:
                res += i+time,
        
        return res
