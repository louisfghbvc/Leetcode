# simple for loop

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        fre = 0
        mx = 0
        for x in nums:
            if x: fre += 1
            else: 
                mx = max(fre, mx)
                fre = 0
        
        mx = max(fre, mx)
        return mx
