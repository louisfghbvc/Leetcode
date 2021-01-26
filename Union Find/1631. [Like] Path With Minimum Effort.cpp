// Okay... So. this is just a Shortest path problem.
// Can also build all edges. and sort them. build them. until start and end are connected.
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    struct node{
        int u, v, c;
        bool operator<(const node n2){
            return c < n2.c;
        } 
    };
    
    int p[10005];
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        memset(p, -1, sizeof p);
        int r = heights.size();
        int c = heights[0].size();
        vector<node> ed;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                for(int k = 0; k < 4; ++k){
                    int ni = i+dir[k][0], nj = j+dir[k][1];
                    if(ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
                    ed.push_back({i*c+j, ni*c+nj, abs(heights[i][j]-heights[ni][nj])});
                }
            }
        }
        sort(ed.begin(), ed.end());
        int res = 0;
        int tar = (r-1)*c + c-1;
        for(int i = 0; i < ed.size(); ++i){
            node e = ed[i];
            int u = find(e.u), v = find(e.v), c = e.c;
            if(u == v) continue;
            p[v] = u;
            res = max(res, c);
            if(find(0) == find(tar)) break;
        }
        
        return res;
    }
};

// Dijkstra. O(MNlogMN). Space Optimal.
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    typedef pair<int, int> ii;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        
        vector<vector<int>> dp(r, vector<int>(c, 1e7));
        dp[0][0] = 0;
        
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, 0});
        
        while(pq.size()){
            auto [cost, id] = pq.top(); pq.pop();
            int pr = id/c, pc = id%c;
            if(pr == r-1 && pc == c-1) return cost;
            for(int k = 0; k < 4; ++k){
                int nr = pr + dir[k][0], nc = pc + dir[k][1];
                if(nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
                int diff = max(cost, abs(heights[nr][nc] - heights[pr][pc]));
                if(diff < dp[nr][nc]){
                    dp[nr][nc] = diff;
                    pq.push({diff, nr*c + nc});
                }
            }
        }
        
        return dp[r-1][c-1];
    }
};
