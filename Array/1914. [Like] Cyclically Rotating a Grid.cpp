// each layer rotate different times!!!!!!!!!!!!!!!!!!

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        int level = min(n,m) / 2;
        
        for(int l = 0; l < level; ++l){
            int tk = k % (m - 2*l + m - 2*l + n - 2*l + n - 2*l - 4); // fuck here. each layer is different
            
            for(int t = 0; t < tk; ++t){
                int i = l, j = l;
                int tmp = grid[i][j];

                // left
                for(; j+1 < n-l; ++j)
                    grid[i][j] = grid[i][j+1];


                // right
                for(; i+1 < m-l; ++i)
                    grid[i][j] = grid[i+1][j];


                for(; j > l; --j)
                    grid[i][j] = grid[i][j-1];


                for(; i > l+1; --i)
                    grid[i][j] = grid[i-1][j];

                grid[i][j] = tmp;
            }
        }
        
        return grid;
    }
};
