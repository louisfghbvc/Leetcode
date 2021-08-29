# simple. sort and min max is edge. 
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        res = float('inf')
        for i in range(k, len(nums)+1, 1):
            res = min(res, nums[i-1] - nums[i-k])
        return res
