# Two pointers. O(N).
class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        i, j = 0, 1
        while j < len(nums) and i < len(nums):
            # odd
            while j < len(nums) and nums[j] % 2: j += 2
            # even
            while i < len(nums) and nums[i] % 2 == 0: i += 2
            
            if j < len(nums) and i < len(nums):
                nums[i], nums[j] = nums[j], nums[i]
        
        return nums
