class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        // goal: find out maximum sum of 3 rooks we can put
        // idea:
        // enumerate middle rook
        // we can preprocess up, down rooks -> they are different row!
        // we just need to make sure the column is different -> using at most 3 

        int m = board.size();
        int n = board[0].size();

        auto up = board, down = board;
        for (int i = 1; i < m; ++i)
            for (int j = 0; j < n; ++j)
                up[i][j] = max(up[i][j], up[i-1][j]);
        for (int i = m-2; i >= 0; --i)
            for (int j = 0; j < n; ++j)
                down[i][j] = max(down[i][j], down[i+1][j]);

        // enumerate middle
        long ans = LLONG_MIN;
        for (int i = 1; i+1 < m; ++i) {
            set<pair<int, int>> u3, d3; // up maximum 3, down maximum 3 
            for (int j = 0; j < n; ++j) {
                u3.insert({up[i-1][j], j});
                d3.insert({down[i+1][j], j});
                if (u3.size() > 3) u3.erase(u3.begin());
                if (d3.size() > 3) d3.erase(d3.begin());
            }
            for (int j = 0; j < n; ++j) {
                for (auto &[a, j1]: u3) {
                    for (auto &[b, j2]: d3) {
                        if (j1 == j || j2 == j1 || j2 == j) continue;
                        ans = max(ans, (long)a + board[i][j] + b);
                    }
                }
            }

        }

        return ans;
    }
};
