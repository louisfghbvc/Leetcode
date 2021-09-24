# fib tweak
class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 1 or n == 2: return 1
        if n == 0: return 0
        
        
        f2, f1, f0 = 1, 1, 0
        f3 = 0
        for i in range(3, n+1):
            f3 = f2 + f1 + f0
            f0 = f1
            f1 = f2
            f2 = f3
        
        return f3 
      
# clean, O(N), consise.
# think 3, since 0 is not use, and 1 ... so on
class Solution:
    def tribonacci(self, n: int) -> int:
        # base
        dp = [0, 1, 1]
        
        for i in range(3, n+1):
            dp[i%3] = sum(dp)
        
        return dp[n%3]
