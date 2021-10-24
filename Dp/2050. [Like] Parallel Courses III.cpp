# topology sort dp. O(E + V)

class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        ind = [0 for _ in range(n)]
        g = [[] for _ in range(n)]
        
        # build graph, and cal indegree
        for u, v in relations:
            u -= 1
            v -= 1
            g[u].append(v)
            ind[v] += 1
        
        # dp[i]: maximum times finish i
        dp = [0 for i in range(n)]
        
        # node, depth
        q = deque()
        for i in range(n):
            if ind[i] == 0:
                q.append(i)
                dp[i] = time[i]
        
        # do bfs
        while q:
            u = q.popleft()
            for v in g[u]:
                dp[v] = max(dp[v], dp[u]+time[v])
                ind[v] -= 1
                if ind[v] == 0:
                    q.append(v)
                         
        return max(dp)
