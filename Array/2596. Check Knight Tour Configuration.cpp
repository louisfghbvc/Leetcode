class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        // goal: check valid
        // idea: backtracking, from top-left
        
        int n = grid.size(); 
        
        int i = 0, j = 0;
        int cnt = 1;
        while (1) {
            bool ok = false;
            for (auto &[ni, nj]: {make_pair(-2, -1), {-2, 1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}}) {
                if (i+ni < 0 || i+ni >= n || j+nj < 0 || j+nj >= n) continue;
                if (grid[i+ni][j+nj] == cnt) {
                    ok = true;
                    i += ni;
                    j += nj;
                    cnt++;
                    break;
                }
            }
            if (!ok) break;
        }
        
        return cnt == n*n; 
    }
};
