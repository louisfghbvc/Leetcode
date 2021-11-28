# BFS. see comments below
# sort time, and build subgraph run bfs
# O(MN)
class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:        
        secret = [0] * n
        secret[0], secret[firstPerson] = 1, 1
        
        # sort the meetings by time
        meetings.sort(key = lambda x: x[2])
        
        # connect a sub graph
        # do all meeting at same time
        graph = defaultdict(list)
        
        def bfs():
            q = deque()
            vis = set()
            for i in graph:
                if secret[i]:
                    vis.add(i)
                    q.append(i)
            while q:
                cur = q.popleft()
                for v in graph[cur]:
                    if v in vis: continue
                    vis.add(v)
                    secret[v] = 1
                    q.append(v)
            
        prev_time = -1
        for a, b, t in meetings:
            if t != prev_time:
                bfs()
                graph = defaultdict(list)
            graph[a].append(b)
            graph[b].append(a)
            prev_time = t
            
        bfs()
        
        return [i for i, v in enumerate(secret) if v]

# Union find, use recover version
class DSU:
    def __init__(self, n):
        self.p = [i for i in range(n)]
        
    def connected(self, a, b):
        return self.find(a) == self.find(b)
    
    def find(self, x):
        if x == self.p[x]: return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def union(self, a, b):
        self.p[self.find(b)] = self.find(a)
    
    def recover(self, x):
        self.p[x] = x
    
class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        dsu = DSU(n)
        dsu.union(0, firstPerson) 
        
        # sort by time
        meetings.sort(key = lambda x: x[2])
        
        i = 0
        while i < len(meetings):
            pipe = []
            time = meetings[i][2]
            
            while i < len(meetings) and meetings[i][2] == time:
                pipe += meetings[i][0],
                pipe += meetings[i][1],
                dsu.union(meetings[i][0], meetings[i][1])
                i += 1
            
            for val in pipe:
                if not dsu.connected(0, val):
                    dsu.recover(val)
        
        return [i for i in range(n) if dsu.connected(0, i)]
