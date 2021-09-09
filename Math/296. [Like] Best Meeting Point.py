# divide dimension to 1D. sorting
# O(MNlogMN)
class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        
        # record the sorted x,y point
        x, y = [], []
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    x.append(i)
                    y.append(j)
        x.sort()
        y.sort()
        
        # get the best point of each axis
        bx, by = x[len(x)//2], y[len(x)//2]
        
        # we just sperate each axis, calculate
        return sum(abs(bx - cx) for cx in x) + sum(abs(by - cy) for cy in y) 
        
# O(MN). since we can just from small to big.
