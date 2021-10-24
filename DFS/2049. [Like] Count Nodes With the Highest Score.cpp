# post order dp. O(N).

class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        n = len(parents)
        g = [[] for _ in range(n)]
        
        # tree
        for i in range(1, n):
            g[parents[i]].append(i)
            g[i].append(parents[i])
            
        # subtree size
        sz = [0 for _ in range(n)]
        
        # cal subtree
        def dfs(u=0, p=-1):
            for v in g[u]:
                if v != p:
                    sz[u] += dfs(v, u)
            sz[u] += 1
            return sz[u]
        
        mx, cnt = 0, 0
        # remove each node
        for i in range(n):
            sz = [0 for _ in range(n)]
            dfs(i)
            val = 1
            for ch in g[i]: val *= sz[ch]
            if val > mx:
                mx, cnt = val, 1
            elif val == mx:
                cnt += 1
        
        return cnt
        
# Do in one dfs.
class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        n = len(parents)
        g = [[] for _ in range(n)]
        
        # tree
        for i in range(1, n):
            g[parents[i]].append(i)
            
        self.fre = 0
        self.mx = 0
        
        # cal subtree size
        def dfs(u):
            subtree_size = 1
            prod = 1
            for v in g[u]:
                child_size = dfs(v)
                subtree_size += child_size
                prod *= child_size
            prod *= (n - subtree_size or 1)
            if prod > self.mx:
                self.mx = prod
                self.fre = 0
            if prod == self.mx:
                self.fre += 1
            return subtree_size

        dfs(0)
        
        return self.fre
