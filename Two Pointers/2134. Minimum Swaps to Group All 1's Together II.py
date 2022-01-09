# sliding window with window size = #1
# O(N)

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        
        # first, count number of 1 in array
        one = nums.count(1)
        
        # edge case, no 1
        if one == 0: return 0
        
        # second, padding the array, made cycle to array
        nums = nums + nums
        
        # sliding the window size = one
        # calculate the #1 in the window
        
        l, r = 0, 0
        cur_one = 0
        ans = n
        while r < len(nums):
            cur_one += nums[r] == 1
            if r - l + 1 == one:
                ans = min(one - cur_one, ans)
                cur_one -= nums[l] == 1
                l += 1
            r += 1
            
        return ans
        
