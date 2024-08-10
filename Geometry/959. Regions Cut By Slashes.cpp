// upscale the grid, and do dfs as graph, tricky

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        // goal: give the grid of nxn find out the number of region
        // idea:

        // consider 1x1, if / or \ -> ans is 2 

        // consider 2x2
        // "/ "
        // "  "  

        // "\ "
        // "  "

        // upscale the grid
        
        int n = grid.size();
        vector<vector<int>> pad(n*3, vector(n*3, 0));

        for (int i = 0, bi = 0; i < n; ++i, bi += 3) {
            for (int j = 0, bj = 0; j < n; ++j, bj += 3) {
                if (grid[i][j] == '/') {
                    pad[bi][bj+2] = pad[bi+1][bj+1] = pad[bi+2][bj] = 1;
                }
                else if (grid[i][j] == '\\') {
                    pad[bi][bj] = pad[bi+1][bj+1] = pad[bi+2][bj+2] = 1;
                }
            }
        }

        // for (int i = 0; i < 3*n; ++i) {
        //     for (int j = 0; j < 3*n; ++j) {
        //         cout << pad[i][j] << " \n"[j+1==3*n];
        //     }
        // }

        auto dfs = [&](auto &self, int i, int j) -> void {
            if (pad[i][j]) return;
            pad[i][j] = 1;
            for (auto &[ni, nj] : {make_pair(i+1,j), {i-1,j}, {i,j-1}, {i,j+1}}) {
                if (ni < 0 || ni >= 3*n || nj < 0 || nj >= 3*n || pad[ni][nj]) continue;
                self(self, ni, nj);
            }
        };

        int ans = 0;
        for (int i = 0; i < 3*n; ++i) {
            for (int j = 0; j < 3*n; ++j) {
                if (pad[i][j] == 0) {
                    dfs(dfs, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
