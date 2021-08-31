# divide and conquer, guess d is positive or negative
# smallest number is all neg. 
# second smallest number is
# (all neg + smallest pos) or (all neg - largest neg) 
# => all neg + smallest abs(val)
# O(N2^N).

class Solution:
    
    def dfs(self, n: int, arr: List[int]) -> List[int]:
        if n == 1: # base case
            return [sum(arr)] if 0 in arr else []
        
        d = arr[1] - arr[0]
        # no matter d is positive, divide arr to 2 group
        # first is remove d, second is first + d, we want delete d.
        
        l, r = 0, 0
        s, t = [], []
        used = set()
        while True:
            while l < (1<<n) and l in used:
                l += 1
            if l == 1<<n: break
            used.add(l)
            s.append(arr[l])
            
            while r in used or arr[r] != arr[l] + d:
                r += 1
            used.add(r)
            t.append(arr[r])
        
        # d is positive
        ans = self.dfs(n-1, s)
        if ans:
            return ans + [d]
        # d is negative
        ans = self.dfs(n-1, t)
        if ans:
            return ans + [-d]
        return []       
    
    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        sums.sort()
        return self.dfs(n, sums)
