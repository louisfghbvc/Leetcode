// Fun problem. check color from big to small.
// and see that when high color if have cycle. 
// O(MNC^2).

class Solution {
public:
    vector<int> vis;
    int m, n;
    
    bool dfs(vector<vector<int>>& targetGrid, int color){
        if(vis[color] == 2) return true;
        if(vis[color] == 1) return false;
        
        int l = INT_MAX, r = INT_MIN, u = l, d = r;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(targetGrid[i][j] == color) l = min(l, j), u = min(i, u), r = max(j, r), d = max(i, d);
        
        if(l == INT_MAX) return true;
        
        vis[color] = 1;
        for(int i = u; i <= d; ++i)
            for(int j = l; j <= r; ++j)
                if(targetGrid[i][j] != color && !dfs(targetGrid, targetGrid[i][j])) return false;
        vis[color] = 2;
        
        return true;
    }
    
    bool isPrintable(vector<vector<int>>& targetGrid) {
        m = targetGrid.size();
        n = targetGrid[0].size();
        
        vis.resize(61);
        for(int c = 60; c >= 0; --c) if(!dfs(targetGrid, c)) return false;
        return true;
    }
};
