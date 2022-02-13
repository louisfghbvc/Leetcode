class Solution:
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        # backtracking
        # try to enumerate all possible
        
        n = len(nums)
        
        @lru_cache(None)
        def dfs(i, mask=0):
            if i == n: return 0
            
            res = 0
            for slot in range(numSlots):
                if not (mask >> (slot*2) & 1):
                    res = max(res, (nums[i] & (slot+1)) + dfs(i+1, mask | (1 << slot*2)))
                elif not (mask >> (slot*2) & 2):
                    res = max(res, (nums[i] & (slot+1)) + dfs(i+1, mask | (1 << (slot*2))))
                    
            return res
        
        return dfs(0)
