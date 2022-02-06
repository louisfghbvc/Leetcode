# heap, sliding window, dp
# O(NlogN)

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        
        # calculate n,
        n = len(nums) // 3
        
        # go through each position
        # maintain left top-n small, right top-n greater
        
        # left part
        left = []
        left_sum = 0
        for i in range(n):
            heapq.heappush(left, -nums[i])
            left_sum += nums[i]
        
        # right part
        right_sum = 0
        right_max = []
        right = []
        for i in range(3*n-1, 2*n-1, -1):
            heapq.heappush(right, nums[i])
            right_sum += nums[i]
        
        right_max = [right_sum]
        for i in range(2*n-1, n-1, -1):
            heapq.heappush(right, nums[i])
            right_sum += nums[i]
            right_sum -= heapq.heappop(right)
            right_max += right_sum,
        
        right_max.reverse()
        
        # all position can enumerate
        res = left_sum - right_max[0]
        for i in range(n, 2*n):
            heapq.heappush(left, -nums[i])
            left_sum += nums[i]
            left_sum += heapq.heappop(left)
            res = min(left_sum - right_max[i-n+1], res)
        
        return res
