class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // goal: count the number of submatrices such that X=Y, at least 1 X
        // idea:
        // prefix count X, and prefix count Y
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> preX(m+1, vector(n+1, 0)), preY(m+1, vector(n+1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                preX[i][j] = preX[i-1][j] + preX[i][j-1] - preX[i-1][j-1] + (grid[i-1][j-1]=='X');
                preY[i][j] = preY[i-1][j] + preY[i][j-1] - preY[i-1][j-1] + (grid[i-1][j-1]=='Y');
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (preX[i][j] > 0 && preX[i][j] == preY[i][j])
                    ans++;
            }
        }
        
        return ans;
    }
};
