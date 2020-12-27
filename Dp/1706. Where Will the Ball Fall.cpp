// this is tag dp. but acutually just simulate.
// O(M*N). check same diagonal. and move. otherwise fail.

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, -1);
        
        for(int j = 0; j < n; ++j){
            int x = 0, y = j;
            bool ok = 1;
            while(ok){
                ok = 0;
                if(x >= m) break;
                
                if(grid[x][y] == 1){
                    if(y+1 < n && grid[x][y+1] == 1){
                        x++, y++;
                        ok = 1;
                    }
                    else break;
                }
                else if(grid[x][y] == -1){
                    if(y-1 >= 0 && grid[x][y-1] == -1){
                        x++, y--;
                        ok = 1;
                    }
                    else break;
                }
            }
            
            if(x >= m) res[j] = y;
        }
        
        
        return res;
    }
};
