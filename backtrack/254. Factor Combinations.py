# recursive use bound. Fast.
# O(sqrt(N)+...). hard to compute.
class Solution:
    def getFactors(self, n: int) -> List[List[int]]:
        def dfs(i, n, tmp, res):
            while i*i <= n:
                if n % i == 0:
                    res += tmp + [i, n//i],
                    dfs(i, n//i, tmp + [i], res)
                i += 1
            return res
        
        return dfs(2, n, [], [])
        
        
# a little slow. self recursive + memo
class Solution:
    @lru_cache(None)
    def getFactors(self, n: int) -> List[List[int]]:
        res = []
        for i in range(2, int(sqrt(n)+1)):
            if n % i == 0:
                res.append([i, n//i])    
                for j in self.getFactors(n // i):
                    if j[0] >= i:
                        res.append([i,*j])
        return res
