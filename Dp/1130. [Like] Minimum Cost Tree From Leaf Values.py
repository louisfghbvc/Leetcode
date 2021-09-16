# segment dp. O(N^3).

class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        # similiar to add parenthesis.
        
        # return type: maximum leaf, sum of nonleaf
        @lru_cache(None)
        def dfs(l, r):
            # Base case
            if l > r: return (0, 0)
            if l == r: return (arr[l], 0)
        
            res = float('inf')
            mx = 0
            for i in range(l, r):
                left, right = dfs(l, i), dfs(i+1, r)
                mx = max(mx, left[0], right[0])
                res = min(res, left[1] + right[1] + left[0] * right[0])

            return (mx, res) 
        
        return dfs(0, len(arr)-1)[1]
      
      

# Greedy appoarch O(N^2), find minimum and remove, since we will not use minimum later.
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        # minimum never use, remove minimum. and get pair from left or right
        
        res = 0
        while len(arr) > 1:
            i = arr.index(min(arr))
            res += min(arr[i-1:i] + arr[i+1:i+2]) * arr.pop(i)
            
        return res



# approach2 but use monotonous Stack O(N), trick
