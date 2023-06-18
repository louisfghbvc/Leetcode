// skip can means nubmer of remain

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // goal: find the minimum cost to paint n walls
        // idea:
        // if we use the paid painter, we can use free
        
        // cost 1,2,2,3
        // time 1,3,2,3  
        //        ^
        // skip number at most n
        
        
        int n = cost.size();
        vector dp(n, vector(3*n, -1));
        
        auto dfs = [&](auto &self, int i, int skip) -> int {
            if (i >= n) return skip >= 0 ? 0 : 1e9;
            
            int &res = dp[i][skip + n];
            if (res != -1) return res;
            
            // used
            res = cost[i] + self(self, i+1, min(skip + time[i], n));
            
            // skip
            res = min(res, self(self, i+1, skip-1));
            
            return res;
        };
        
        return dfs(dfs, 0, 0);
    }
};
