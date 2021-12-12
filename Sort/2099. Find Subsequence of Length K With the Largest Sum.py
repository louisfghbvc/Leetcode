// use heap and maintain the origin index.
// O(NlogK)

class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        pq = []
        
        # pop out minimum value, maintain size k
        for i, x in enumerate(nums):
            heapq.heappush(pq, (x, i))
            if len(pq) > k:
                heapq.heappop(pq)
        
        pq.sort(key=lambda x: x[1])
        
        return [nums[i] for x, i in pq]
        
