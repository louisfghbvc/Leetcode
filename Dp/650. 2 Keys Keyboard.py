# just find out prime factor that can be divisible, can get n//i cost.
# O(N^2).

class Solution:
    @lru_cache(None)
    def minSteps(self, n: int) -> int:
        # base case
        if n <= 1: return 0
        return min(n//i + self.minSteps(i) for i in range(n-1, 0, -1) if n % i == 0)
