// space optimal. T:O(N), S:O(1).
// use origin array. awesome. just dp.
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        for(int i = 1; i < costs.size(); ++i){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};

// T: O(N). S: O(N)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        vector<int> dp = costs[0];
        for(int i = 1; i < costs.size(); ++i){
            vector<int> ndp(3, INT_MAX);
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k) if(k != j){
                    // ndp[k] is from dp[j]
                    ndp[k] = min(ndp[k], dp[j] + costs[i][k]);
                }
            }
            dp = move(ndp);
        }
            
        return *min_element(dp.begin(), dp.end());
    }
};
