class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // goal: find the order of traverse the grid
        // idea:
        // each time we are doing two times length traverse
        // go the index and when index is in bound record it
        // x x x x
        // x 1 2 3 4
        // x x x 

        // right -> down -> left -> up

        vector<vector<int>> res;

        int go[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        auto dfs = [&](auto &self, int i, int j, int len, int cnt, int dir=0) -> void {
            if (res.size() == rows * cols) return;
            for (int k = 0; k < len; ++k) {
                i += go[dir][0];
                j += go[dir][1];
                if (i >= 0 && i < rows && j >= 0 && j < cols)
                    res.push_back({i, j});
            }
            cnt++;
            if (cnt == 2) cnt = 0, len++;
            self(self, i, j, len, cnt, (dir+1)%4);
        };

        res.push_back({rStart, cStart});
        dfs(dfs, rStart, cStart, 1, 0);

        return res;
    }
};
