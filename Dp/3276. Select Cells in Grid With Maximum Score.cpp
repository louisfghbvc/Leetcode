class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        // goal: max the score
        // we can choose each value in the row
        // we will choose as the set

        // idea:
        // a[i][j] > 0
        // we can make each row is sorted
        // n=2
        // [x1  x2]
        // [x2  x3] => x2 + x3
        // n=2
        // [x1  x3]
        // [x2  x3] => x3 + max(x2,x1)

        // [x1, x2, x3]
        // [x1, x2, x3]
        // [x1, x2, x3] => 
        // greedy may not work -> the movement where x2 is same
        // we need to try all possible => O(n^m)
        // sort by values
        // 5 4 3  
        // 5 4 2

        // consider dp
        // using bitmask
        // iterate the value
        // record value -> {index, }
        // dp[i][mask]: starting from value i, what is the maximum sum
        // each i, we try to check the value index
        // of skip i

        int n = grid.size();
        vector<vector<int>> idx(105);
        for (int i = 0; i < n; ++i)
            for (int x: grid[i]) 
                idx[x].push_back(i);

        vector dp(105, vector(1<<n, -1));
        auto dfs = [&](auto &self, int i, int mask) {
            if (i > 100 || mask == (1<<n)-1) return 0;

            int& res = dp[i][mask];
            if (res != -1) return res;

            res = self(self, i+1, mask);
            for (int row: idx[i]) {
                if (mask >> row & 1) continue;
                res = max(res, i + self(self, i+1, mask | (1<<row)));
            }

            return res;
        };

        return dfs(dfs, 1, 0);
    }
};
