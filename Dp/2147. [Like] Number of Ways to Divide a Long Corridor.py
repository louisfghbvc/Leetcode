# comb dp
# O(N), space O(1)

class Solution:
    def numberOfWays(self, s: str) -> int:
        # base case seats must be even
        seats = s.count('S')
        if seats == 2: return 1
        if seats == 0 or seats % 2: return 0
        
        mod = 10**9+7
        
        # when have two seats, add a divider
        ways, cnt = 0, 0
        res = 1
        
        for c in s:
            cnt += c == 'S'
            if cnt == 2:
                ways += 1
            elif cnt == 3:
                res *= ways
                res %= mod
                cnt = 1
                ways = 0
                
        return res
