# Greedy. and simple math. O(N).
# just put avg, and if mod not 0, means some number should add 1

class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        m_sum = sum(rolls)
        tot_sum = (m+n) * mean
        
        n_sum = tot_sum - m_sum
        
        if not (6*n >= n_sum >= n):
            return []

        if n_sum % n != 0:
            return [n_sum // n + 1] * (n_sum % n) + [n_sum // n] * (n - n_sum % n)
        
        return [n_sum // n] * n
