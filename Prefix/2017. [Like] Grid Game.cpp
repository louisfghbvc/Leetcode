// observe that second robot only have 2 choice. first row suffix, second row prefix.
// O(N).

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long res = LLONG_MAX;
        
        int n = grid[0].size();
        long suf = accumulate(grid[0].begin(), grid[0].end(), 0L);
        
        long prev = 0;
        for(int j = 0; j < n; ++j){
            suf -= grid[0][j];
            res = min(res, max(prev, suf));
            prev += grid[1][j];
        }
        
        return res;
    }
};
