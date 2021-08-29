# simple heap, nth element
class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        pq = []
        for x in nums:
            heapq.heappush(pq, int(x))
            if len(pq) > k:
                heapq.heappop(pq)
        return str(pq[0])
