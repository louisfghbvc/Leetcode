# BFS, then calculate lastday that send message.

class Solution:
    def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:
        n = len(patience)
        
        # build graph
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        
        # distance from server
        dp = [int(1e9)] * n
        
        q = deque()
        q.append((0, 0))
        dp[0] = 0
        # bfs
        while q:
            u, cost = q.popleft()
            if cost > dp[u]: continue
            dp[u] = cost
            for v in g[u]:
                if dp[v] > cost + 1:
                    dp[v] = cost+1
                    q.append((v, cost+1))
        
        res = 0
        for i, x in enumerate(dp):
            # receive: 2*x
            lastday = 0
            
            if 2*x > patience[i]:
                lastday = (2*x-1) // patience[i] * patience[i]
            
            res = max(res, lastday + 2*x)   
        
        return res+1
