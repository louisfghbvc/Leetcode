# euler path, remember postorder
# O(N)

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        # convert to the graph problem
        # euler path
        
        in_degree, out_degree = defaultdict(int), defaultdict(int)
        graph = defaultdict(list)
        
        start = 0
        for u, v in pairs:
            start = u
            in_degree[v] += 1
            out_degree[u] += 1
            graph[u].append(v)
            
        for u, v in pairs:
            if in_degree[u]+1 == out_degree[u]:
                start = u
                break
            if in_degree[v]+1 == out_degree[v]:
                start = v
                break
        
        self.res = []
        def dfs(u):
            while graph[u]:
                v = graph[u].pop()
                dfs(v)
                self.res += [u, v],
        
        dfs(start)
        
        return self.res[::-1]
                
