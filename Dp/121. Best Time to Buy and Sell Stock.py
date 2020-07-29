// O(N). Autually not dp. Like mono
// Just get minimum is enough.
// because only one transaction.
// like rolling value.

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if not n: return 0
        sell, mn = 0, prices[0]
        for i in range(1, n):
            sell = max(sell, prices[i] - mn)
            mn = min(mn, prices[i])
        return sell
        
