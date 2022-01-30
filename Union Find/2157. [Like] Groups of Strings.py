class DSU:
    def __init__(self, n):
        self.p = [-1 for i in range(n)]
        
    def find(self, x):
        if self.p[x] < 0: return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y: return False
        if self.p[x] > self.p[y]: x, y = y, x
        self.p[x] += self.p[y]
        self.p[y] = x
        return True
        
class Solution:
    def groupStrings(self, words: List[str]) -> List[int]:
        # one-one compare -> TLE
        
        def conv(s):
            val = 0
            for c in s:
                val |= 1 << (ord(c) - 97)
            return val
        
        # convert word into int
        # enumerate all bit
        
        n = len(words)
        group = n
        mp = defaultdict(int)
        dsu = DSU(n)
        
        for i in range(n):
            mask = conv(words[i])
            for j in range(26):
                # del or add one letter
                tmp = mask ^ (1<<j)
                if tmp in mp:
                    group -= dsu.union(mp[tmp], i)
                
                # replace to *
                if mask >> j & 1:
                    tmp |= 1<<26
                    if tmp in mp:
                        group -= dsu.union(mp[tmp], i)
                    # push to mp
                    mp[tmp] = i
                    
            mp[mask] = i
            
        return [group, max(-dsu.p[dsu.find(i)] for i in range(n))]
