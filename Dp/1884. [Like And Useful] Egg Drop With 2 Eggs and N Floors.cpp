// Top down, tricky dp.
// O(N^2).

class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int floors, int eggs){
        if(floors <= 1 || eggs == 1) return floors; // base case
        int &res = dp[floors][eggs];
        if(res != -1) return res;
        res = INT_MAX;
        for(int f = 1; f <= floors; ++f){
            res = min(res, 
                     // broken, not broken
                     1 + max(dfs(f - 1, eggs - 1), dfs(floors - f, eggs))
                     );
        }
        return res;
    }
    
    int twoEggDrop(int n) {
        dp = vector<vector<int>>(n+1, vector<int>(3, -1));
        return dfs(n, 2);
    }
};
