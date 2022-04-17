class Solution {
public:
    
    pair<int, int> cal(int x) {
        pair<int, int> res;
        while (x % 2 == 0) res.first++, x /= 2;
        while (x % 5 == 0) res.second++, x /= 5;
        return res;
    }
    
    int helper(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        
        // build the suffix
        vector<pair<int, int>> soFar(n); // from top to current row
        
        for (int i = 0; i < m; ++i) {
            // update sofar
            for (int j = 0; j < n; ++j) {
                auto tmp = cal(grid[i][j]);
                soFar[j].first += tmp.first;
                soFar[j].second += tmp.second;
            }
            
            vector<pair<int, int>> suf(n+1);
            for (int j = n-1; j >= 0; --j) {
                auto tmp = cal(grid[i][j]);
                suf[j] = {suf[j+1].first + tmp.first, suf[j+1].second + tmp.second};
            }
            
            pair<int, int> pre;
            for (int j = 0; j < n; ++j) {
                // -|
                pair<int, int> cnt1 = {soFar[j].first + pre.first, soFar[j].second + pre.second};
                res = max(res, min(cnt1.first, cnt1.second));
                // L
                pair<int, int> cnt2 = {soFar[j].first + suf[j+1].first, soFar[j].second + suf[j+1].second};
                res = max(res, min(cnt2.first, cnt2.second));
                // update pre
                pre.first += cal(grid[i][j]).first;
                pre.second += cal(grid[i][j]).second;
            }
        }
        
        return res;
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        // goal: a path that is only at most one turn
        // idea: only 2 and 5 cnt
        // only some cases
        // only consider L shape
        
        int ans = helper(grid);
        reverse(grid.begin(), grid.end());
        ans = max(ans, helper(grid));
        
        return ans;
    }
};
