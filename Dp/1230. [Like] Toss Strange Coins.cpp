// Dp. top down, choose or not choose
// O(N*target)

class Solution {
public:
    double dp[1005][1005];
    bool vis[1005][1005];
    
    vector<double> arr;
    int target;
    
    double dfs(int i, int cnt){
        if(i == arr.size()) return cnt == target; 
        if(vis[i][cnt]) return dp[i][cnt];
        vis[i][cnt] = 1;
        return dp[i][cnt] = arr[i] * dfs(i+1, cnt+1) + (1.0-arr[i]) * dfs(i+1, cnt);
    }
    
    double probabilityOfHeads(vector<double>& prob, int target) {
        arr = prob;
        this->target = target;
        return dfs(0, 0);
    }
};

// Bottom up. T: O(N*target).
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        
        vector<vector<double>> dp(n+1, vector<double>(target+1));
        
        // base
        dp[0][0] = 1;
        
        // all choose tail
        for(int i = 1; i <= n; ++i)
            dp[i][0] = dp[i-1][0] * (1-prob[i-1]);
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= target; ++j){
                dp[i][j] = dp[i-1][j-1] * prob[i-1] + dp[i-1][j] * (1-prob[i-1]); 
            }
        }
        
        return dp[n][target];
    }
};

// Bottom up, Optimal. T: O(N*target). S: O(target)
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        
        vector<double> dp(target+1);
        
        // base, no choose head
        dp[0] = 1;
        
        // try to do dp, each have two choose. head and tail
        for(int i = 0; i < n; ++i){
            for(int j = min(i+1, target); j >= 0; --j){ // cur head max is i+1
                dp[j] = (j ? dp[j-1] : 0) * prob[i] + dp[j] * (1-prob[i]); 
            }
        }
        
        return dp[target];
    }
};
