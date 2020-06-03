// two groups size are same, sort difference smaller. make balance.
// O(NlogN)

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
            return (a[0]-a[1] < b[0]-b[1]);
        });
        int ans = 0;
        for(int i= 0; i < costs.size()/2; ++i){
            ans += costs[i][0] + costs[i+costs.size()/2][1];
        }
        return ans;
    }
};

// O(N^2), Dp, Topdown, each person can go to A or B
class Solution {
public:
    vector<vector<int>> c;
    int n;
    int memo[105][105];
    int dfs(int a, int b, int p){
        if(a > n || b > n) return 1e9;
        if(a == n && b == n) return 0;
        if(memo[a][b] != -1) return memo[a][b];
        return memo[a][b] = min(c[p][0]+dfs(a+1, b, p+1), c[p][1]+dfs(a, b+1, p+1));
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(memo, -1, sizeof memo);
        c = costs;
        n = costs.size()/2;
        return dfs(0, 0, 0);
    }
};
