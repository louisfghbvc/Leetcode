# dp + binary search
# O(NlogN). dp record maximum value so far.

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key = lambda x: x[1])
        
        # dp[endtime] maximum value
        dp = [[0, 0]]
        
        res = 0
        
        for l, r, v in events:
            idx = bisect_left(dp, [l]) - 1
            if v > dp[-1][1]: dp.append([r, v])
            res = max(v + dp[idx][1], res)
        
        return res
        
