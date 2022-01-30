# O(N)
# two pass

class Solution:
    def getDivisionIndices(self, nums: List[int]) -> List[int]:
        
        # first count the numbers of one
        one = nums.count(1)
        
        # second go for loop
        # record the ans, record the maximum score
        
        zero = 0
        mx_score = 0
        ans = []
        
        for i in range(len(nums)+1):
            cur = zero + one
            if cur > mx_score:
                mx_score = cur
                ans = [i]
            elif cur == mx_score:
                ans += i,
            
            if i != len(nums):
                zero += nums[i] == 0
                one -= nums[i] == 1
        
        return ans
