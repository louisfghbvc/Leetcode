# Use bfs to record first and second minimum
# take O(E + V)
# after that just calculate the true time
# change doesn't affect answer
# and second minimum is always shortest add 1 or add2

class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        
        g = [[] for _ in range(n)]
        
        # build graph
        for u, v in edges:
            g[u-1].append(v-1)
            g[v-1].append(u-1)
        
        # 2 case
        # first, shortest path add a edge
        # second, shortest path add 2 edges
        
        def shortest_path2():
            q = deque()
            
            # record the first and second minimum
            dp = [[float('inf'), float('inf')] for _ in range(n)]
            
            # u, length
            q.append((0, 0))
            # first minimum
            dp[0][0] = 0

            while q:
                u, cur_time = q.popleft()
                for v in g[u]:
                    if dp[v][0] > cur_time + 1:
                        dp[v][1] = dp[v][0]
                        dp[v][0] = cur_time + 1
                        q.append((v, dp[v][0]))
                    elif dp[v][1] > cur_time + 1 and cur_time + 1 != dp[v][0]:
                        dp[v][1] = cur_time + 1
                        q.append((v, dp[v][1]))

            return dp[n-1]
        
        # always can find second minimum
        first, second = shortest_path2()
        
        ans = 0
        for i in range(second):
            red = (ans // change) % 2 # odd is red, need wait
            ans = ans + time + (change-ans%change) if red else ans + time
                
        return ans
