# two pass, dp O(N)

class Solution:
    def minimumCost(self, s: str) -> int:
        # two pass
        n = len(s)
        
        # first pass is from left to right
        left = [0] * (n+1) 
        for i in range(n):
            if s[i] == '1':
                left[i] = min(left[i-1] + 2, i+1)
            else:
                left[i] = left[i-1]
        
        # second pass is from right to left
        right = [0] * (n+1) 
        for i in range(n-1, -1, -1):
            if s[i] == '1':
                right[i] = min(right[i+1] + 2, n-i)
            else:
                right[i] = right[i+1]

        ans = float('inf')
        for i in range(n):
            ans = min(ans, left[i]+right[i+1])
            
        return ans
