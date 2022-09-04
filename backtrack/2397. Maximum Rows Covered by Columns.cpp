class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        // goal: find the maximum row can be covered, if we choose the any set that size is cols
        // idea: backtracking
        
        // O(m * n * Cn_cols), largest -> 12!/6!
        
        int m = mat.size(), n = mat[0].size();
        
        vector<bool> choose_col(n);
        auto test = [&]() {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                bool ok = true;
                for (int j = 0; j < n && ok; ++j) {
                    if (mat[i][j]) {
                        if (choose_col[j] == 0) ok = false;
                    } 
                }
                cnt += ok;
            }    
            return cnt;
        };
        
        int ans = 0;
        auto dfs = [&](const auto &self, int i, int remain) {
            if (i == n) {
                if (remain == 0) {
                    ans = max(ans, test());
                }
                return;
            }
            
            // skip i col
            self(self, i+1, remain);
            
            choose_col[i] = true;
            self(self, i+1, remain-1);
            choose_col[i] = false;
        };
        
        
        dfs(dfs, 0, cols);
        
        return ans;
    }
};
