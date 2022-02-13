# base on sort O(max(A)).

class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        
        # [1, 4, 5, 6]
        # from small to big, try to remove that bag
        
        
        tot = sum(beans)
        
        # counting sort
        bucket = [0] * (10**5+1)
        for x in beans:
            bucket[x] += 1
        sort_arr = []   
        for i in range(len(bucket)):
            for _ in range(bucket[i]):
                sort_arr += i,
        
        n = len(beans)
        beans = sort_arr
        
        ans = float('inf')

        drop = 0
        for x in beans:
            ans = min(drop + tot - x * n, ans)
            tot -= x
            n -= 1
            drop += x
        
        return ans
