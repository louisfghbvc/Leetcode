# brute force.

class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        
        n = n+1
        while 1:
            mp = Counter(str(n))
            for d in range(1, 10):
                if mp[str(d)] > 0 and mp[str(d)] != d: break
            else: return n
            n += 1
            
# use pattern to generate.

                
        
        
