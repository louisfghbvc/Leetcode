# convert to graph problem
# build edge O(N^2)
# time complexity O(N^3)

class Solution:
    def maximumDetonation(self, bombs: List[List[int]], ranges: List[int]) -> int:
        
        # build the graph
        n = len(bombs)
        
        g = [[] for i in range(n)]
        
        def dis(a, b):
            return sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2)
        
        for i in range(n):
            for j in range(i+1, n):
                d = dis(bombs[i], bombs[j])
                if d <= ranges[i]:
                    g[i].append(j)
                if d <= ranges[j]:
                    g[j].append(i)
        
        
        # dfs from each to cal maximum depth
        def dfs(u, vis):
            vis.add(u)
            res = 1
            for v in g[u]:
                if v not in vis:
                    res += dfs(v, vis)
            return res
        
        mx = 0
        for i in range(n):
            vis = set()
            mx = max(mx, dfs(i, vis))
        return mx
