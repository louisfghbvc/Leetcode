# Time: O(N), Space O(N)
# record prefix sum

class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        
        # record the prefix sum
        # sliding window size k
        pre = [0]
        for x in nums:
            pre += pre[-1] + x,
        
        res = []
        for i in range(len(nums)):
            if i-k >= 0 and i+k < len(nums):
                res += ceil((pre[i+k+1] - pre[i-k]) / (2*k+1)), 
            else:
                res += -1,
        return res
      
# two pointers, sliding window
# space O(1)
