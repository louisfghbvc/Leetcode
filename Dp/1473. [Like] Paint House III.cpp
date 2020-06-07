// solve it !! but Contest end.
// Memorize, Enum all case, and pc means parent color, g means group size
// if painted, can't paint again
// because g can adjust to get min, so dp is 3-dimension
// I stick with 2-dimension, and debug until end...
// O(n * n * m * target)

class Solution {
public:
    vector<int> h;
    vector<vector<int>> cost;
    int m, n, t;
    int memo[105][105][105];
    int dfs(int g, int i, int pc){
        if(i >= m){
            if(g == t) return 0;
            return 1e9;
        }
        if(memo[g][i][pc] != -1) return memo[g][i][pc];
        if(h[i]){
            return memo[g][i][pc] = dfs(g+(pc != h[i]), i+1, h[i]);
        }
        int mx = INT_MAX;
        for(int c = 1; c <= n; ++c){
            mx = min(mx, cost[i][c-1] + dfs(g+(pc != c), i+1, c));
        }
        return memo[g][i][pc] = mx;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo, -1, sizeof memo);
        this->cost = cost;
        this->m = m;
        this->n = n;
        h = houses;
        t = target;
        
        int res = dfs(0, 0, 0);
        return res >= 1e9 ? -1 : res;
    }
};
