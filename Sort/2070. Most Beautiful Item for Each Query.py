# sort, and offline query
# O(NlogN)

class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort(key = lambda x: x[0])
        
        # do query offline
        arr = []
        for i, q in enumerate(queries):
            arr += (q, i),
        
        arr.sort(key = lambda x: x[0])
        
        ans = [0] * len(arr)
        i = 0
        mx = 1
        for q, idx in arr:
            while i < len(items) and items[i][0] <= q:
                mx = max(mx, items[i][1])
                i += 1
            ans[idx] = mx
        
        return ans
