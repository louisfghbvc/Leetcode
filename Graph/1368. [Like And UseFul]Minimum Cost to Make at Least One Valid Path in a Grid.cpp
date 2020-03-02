//dijkstrka, Tricky! 52ms 11.3MB
class Solution {
public:
    struct node{
        int x, y, w;  
        bool operator<(const node& n2) const{
            return w > n2.w;
        }
    };
    
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
        bool vis[m + 1][n + 1] = {};
        
        priority_queue<node> pq;
        dp[0][0] = 0;
        pq.push({0, 0, 0});
        
        while(!pq.empty()){
            node cur = pq.top(); pq.pop();
            vis[cur.x][cur.y] = true;
            
            if(cur.x == m - 1 && cur.y == n - 1)
                return cur.w;
            
            for(int k = 0; k < 4; ++k){
                int x = cur.x + dir[k][0], y = cur.y + dir[k][1];
                if(x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) continue;
                int cost = 1;
                if(grid[cur.x][cur.y] - 1 == k){
                    cost = 0;
                }
                if(dp[x][y] > cur.w + cost){
                    dp[x][y] = cur.w + cost;
                    pq.push({x, y, dp[x][y]});
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

//deque 28ms 19.9MB, Tricky!
class Solution {
public:
    
    struct node{
        int x, y, w;  
        bool operator<(const node& n2) const{
            return w > n2.w;
        }
    };
    
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
        bool vis[m + 1][n + 1] = {};
        
        deque<node> dq;
        dp[0][0] = 0;
        dq.push_front({0, 0, 0});
        
        while(!dq.empty()){
            node cur = dq.front(); dq.pop_front();
            vis[cur.x][cur.y] = true;
            
            if(cur.x == m - 1 && cur.y == n - 1)
                return cur.w;
            
            for(int k = 0; k < 4; ++k){
                int x = cur.x + dir[k][0], y = cur.y + dir[k][1];
                if(x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) continue;
                if(grid[cur.x][cur.y] - 1 == k){
                    if(dp[x][y] > cur.w){
                        dp[x][y] = cur.w;
                        dq.push_front({x, y, dp[x][y]});
                    }
                }
                else{
                    if(dp[x][y] > cur.w + 1){
                        dp[x][y] = cur.w + 1;
                        dq.push_back({x, y, dp[x][y]});
                    }
                }
                
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
