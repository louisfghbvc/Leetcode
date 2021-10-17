# O(2^N). backtracking

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        
        n = len(nums)
        
        # record the frequecy only use a value
        max_or, fre = 0, 0
        
        # enumerate all non-empty subset
        for mask in range(1<<n):
            val = 0
            for i in range(n):
                if mask & (1<<i):
                    val |= nums[i]

            if val > max_or:
                max_or, fre = val, 1
            elif val == max_or:
                fre += 1
        
        return fre
