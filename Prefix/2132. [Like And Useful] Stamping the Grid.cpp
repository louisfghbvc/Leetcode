// 2D prefix sum
// update use point update strategy
// O(MN), space O(MN)

// first check if region is all zero
// then color that rectangle. use point update
// line sweeep
// simulate

class Solution {
public:
    
    vector<vector<int>> build2D(vector<vector<int>> &arr){
        vector<vector<int>> mat(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + arr[i-1][j-1];
            }
        }
        return mat;
    }
    
    int query(vector<vector<int>> &sum, int l, int r, int u, int d){
        return sum[d][r] - sum[d][l-1] - sum[u-1][r] + sum[u-1][l-1];
    }
    
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        m = grid.size(), n = grid[0].size();
        auto mat = build2D(grid);
        
        vector<vector<int>> diff(m+1, vector<int>(n+1));
        for(int i = 0; i + stampHeight <= m; ++i){
            for(int j = 0; j + stampWidth <= n; ++j){
                if(query(mat, j+1, j+stampWidth, i+1, i+stampHeight) == 0){
                    diff[i][j] += 1;
                    diff[i][j+stampWidth] -= 1;
                    diff[i+stampHeight][j] -= 1;
                    diff[i+stampHeight][j+stampWidth] += 1;
                }
            }
        }
        
        mat = build2D(diff);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0 && !mat[i+1][j+1]) return false;
            }
        }
        return true;
    }
    
private:
    int m, n;
};
