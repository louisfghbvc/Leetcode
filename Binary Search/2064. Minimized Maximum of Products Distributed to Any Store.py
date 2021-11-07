# guess the ans
# O(NlogX).

class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        m = len(quantities)
        
        
        def check(x):
            cnt = 0
            for val in quantities:
                cnt += ceil(val / x)
            return cnt <= n
        
        l, r = 1, 10**5
        ans = -1
        while l <= r:
            mid = (l+r)//2
            if check(mid):
                ans = mid
                r = mid-1
            else:
                l = mid+1
        
        return ans
