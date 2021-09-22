# do bfs from the building.
# and use array to calculate the distance and hit cnts.
# O(M^2N^2)

class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        dis = [[0 for _ in range(n)] for _ in range(m)]
        cnt = [[0 for _ in range(n)] for _ in range(m)]
        
        building = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    building += 1
                    
                    # do bfs
                    q = deque([(i, j, 1)])
                    
                    # visited array
                    vis = [[0 for _ in range(n)] for _ in range(m)]
                    
                    while q:
                        x, y, d = q.popleft()
                        for nx, ny in (x+1, y), (x-1, y), (x, y-1), (x, y+1):
                            if m > nx >= 0 and n > ny >= 0 and not vis[nx][ny] and not grid[nx][ny]: 
                                vis[nx][ny] = 1
                                dis[nx][ny] += d
                                cnt[nx][ny] += 1
                                q.append((nx, ny, d+1))
        
        return min([dis[i][j] for i in range(m) for j in range(n) if grid[i][j] == 0 and cnt[i][j] == building] or [-1])
