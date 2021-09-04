# use prefix sum.
# check forloop O(1)
class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        tot = sum(nums)
        n = len(nums)
        suf = [0] * n
        suf[-1] = nums[-1]
        for i in range(n-2, -1, -1):
            suf[i] += suf[i+1] + nums[i]
            
        for i in range(n):
            suff = suf[i+1] if i+1 != n else 0
            if tot - nums[i]== 2*suff:
                return i
            
        return -1
