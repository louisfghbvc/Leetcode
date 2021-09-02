# convert problem to find valid topologal order. O(N)
# a lots of edge case, careful

class Solution:

    def alienOrder(self, words: List[str]) -> str:
        
        ind = [0] * 26
        graph = defaultdict(list)
        appear = set([ord(c) - ord('a') for word in words for c in word]) 
        
        # compare words[i-1], words[i]
        # build graph
        for i in range(1, len(words)):
            j = 0
            Found = False
            while j < len(words[i-1]) and j < len(words[i]):
                # add edge
                if words[i-1][j] != words[i][j]:
                    ind[ord(words[i][j]) - ord('a')] += 1
                    graph[ord(words[i-1][j]) - ord('a')].append(ord(words[i][j]) - ord('a'))
                    Found = True
                    break
                j += 1
            # since prefix is same, and we need to check
            if not Found and len(words[i-1]) > len(words[i]): return ""
        
        self.res = ''
        # 0 is not visited, 1 is visiting, 2 is end
        color = [0] * 26 
        # topological dfs. and check cycle
        def dfs(u: int) -> bool:
            if color[u]: return color[u] == 2
            color[u] = 1
            for v in graph[u]:
                if not dfs(v): return False
            color[u] = 2
            self.res += chr(97 + u)
            return True
        
        # go dfs from indegree is zero
        for i in appear:
            if ind[i] == 0 and not dfs(i): return ""
        
        # edge case, we must use all char.
        if len(self.res) < len(appear): return ""
        return self.res[::-1]

    
# BFS
class Solution:

    def alienOrder(self, words: List[str]) -> str:
        
        ind = [0] * 26
        graph = defaultdict(list)
        appear = {ord(c) - ord('a') for word in words for c in word}
        
        # compare words[i-1], words[i]
        # build graph
        for i in range(1, len(words)):
            j = 0
            Found = False
            while j < len(words[i-1]) and j < len(words[i]):
                # add edge
                if words[i-1][j] != words[i][j]:
                    ind[ord(words[i][j]) - ord('a')] += 1
                    graph[ord(words[i-1][j]) - ord('a')].append(ord(words[i][j]) - ord('a'))
                    Found = True
                    break
                j += 1
            if not Found and len(words[i-1]) > len(words[i]): return ""
        
        q = deque()
        res = ''
        for i in appear:
            if ind[i] == 0:
                res += chr(i + 97)
                q.append(i)
        
        # topological bfs
        while q:
            u = q.popleft()
            for v in graph[u]:
                ind[v] -= 1
                if ind[v] == 0:
                    res += chr(v + 97)
                    q.append(v)
        
        return res if len(res) == len(appear) else '' 
