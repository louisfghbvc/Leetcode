# BFS, and sort
# O(mn log mn)

class Solution:
    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        res = []
        
        m, n = len(grid), len(grid[0])
        
        vis = set()
        q = deque()
        
        # distance, cur row, cur col
        q.append((0, start[0], start[1]))
        vis.add(tuple(start))
        
        while q:
            d, row, col = q[0]
            q.popleft()
            if pricing[0] <= grid[row][col] <= pricing[1]:
                res += [d, grid[row][col], row, col],
            for nr, nc in [(row+1, col), (row-1, col), (row, col-1), (row, col+1)]:
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] and(nr, nc) not in vis:
                    vis.add((nr, nc))
                    q.append((d+1, nr, nc))
        
        return [[c,d] for a,b,c,d in sorted(res)[:k]]
