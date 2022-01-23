# boring

class Solution:
    def countElements(self, nums: List[int]) -> int:
        nums.sort()
        
        cnt = 0
        for i in range(1, len(nums)-1, 1):
            if nums[-1] > nums[i] > nums[0]:
                cnt += 1
        return cnt
