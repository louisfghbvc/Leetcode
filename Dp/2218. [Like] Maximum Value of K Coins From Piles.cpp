// O(KM?NM).
// top down memo

class Solution {
public:
    
    int dfs(int i, int k) {
        // base 
        if (i >= piles.size()) return 0;
        
        int &res = dp[i][k];
        if (res != -1) return res;
        
        // no use
        res = dfs(i+1, k);
        
        // up to k
        int sum = 0;
        for (int j = 0; j < min((int)piles[i].size(), k); ++j) { // 
            sum += piles[i][j];
            res = max(sum + dfs(i+1, k-j-1), res);
        }
        
        return res;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        this->piles = piles;
        dp = vector<vector<int>> (piles.size(), vector<int>(k+1, -1));
        // idea: dp[i][k] -> maximum so far use 0~i pile, and remain is k
        // transition is : dp[i][k] = max(piles[i][0:j] + dfs(i+1, k-j)) 
        
        return dfs(0, k);
    }
private:
    vector<vector<int>> piles, dp;
};
