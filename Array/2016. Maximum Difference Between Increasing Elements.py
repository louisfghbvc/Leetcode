# BF. O(N^2)

# record minimum. O(N)
class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        mn = nums[0]
        for i in range(1, n):
            res = max(res, nums[i] - mn)
            mn = min(mn, nums[i])
        
        return res if res > 0 else -1
