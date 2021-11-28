# see comments below
# 3 case.

class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        # find the maximum and minimum value in nums
        mx, mn = max(nums), min(nums)
        i, j = nums.index(mx), nums.index(mn)
        
        # maintain i < j
        if i > j: i, j = j, i
        
        # case1, remove j from prefix
        # case2, remove i from suffix
        # case3, remove i from prefix and remove j from suffix

        return min(j+1, len(nums)-i, i+1+len(nums)-j)
