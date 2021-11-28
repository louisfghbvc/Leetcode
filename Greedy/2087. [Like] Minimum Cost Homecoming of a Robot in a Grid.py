# all shortest path cost are all the same
# observe conclusion
# O(M*N)

class Solution:
    def minCost(self, startRow: int, startCol: int, homeRow: int, homeCol: int, rowCosts: List[int], colCosts: List[int]) -> int:
        
        # base case
        if (startRow, startCol) == (homeRow, homeCol): return 0
            
        # observe that, we must going down, and going right
        
        ans = 0
        # going down, up
        while startRow < homeRow:
            startRow += 1
            ans += rowCosts[startRow]
        while startRow > homeRow:
            startRow -= 1
            ans += rowCosts[startRow]
        
        # going left, right
        while startCol < homeCol:
            startCol += 1
            ans += colCosts[startCol]
        while startCol > homeCol:
            startCol -= 1
            ans += colCosts[startCol]
        
        return ans
        
        
        
