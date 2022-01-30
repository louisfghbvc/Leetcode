# brute force until not found
# O(N^2)
class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        
        while original in nums:
            original *= 2
        
        return original

# use hashtable
# O(N)

