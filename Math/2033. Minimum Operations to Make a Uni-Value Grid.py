# make all medium
# O(mnlog(mn))
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        if len(grid) == 0: return 0
        
        m, n = len(grid), len(grid[0])
        
        arr = sorted(grid[i][j] for i in range(m) for j in range(n))
        
        # check grid, mod value is all the same
        p = -1
        for val in arr:
            if p == -1:
                p = val%x
            elif p != val%x: return -1
        
        # if all the same. find middle value, and calculate operations
        mid = arr[m*n//2]
        
        return sum(abs(val-mid)//x for val in arr)
        
        
