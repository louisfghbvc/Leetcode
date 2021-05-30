// Convert problem to fix skip, minimum hour to finish all road.
// O(N^2). Tricky

class Solution {
public:
    vector<vector<int>> dp; // cur i, use k skips.
    vector<int> arr;
    int n, speed;
    
    int dfs(int i, int k){
        if(i < 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        
        int res = (dfs(i-1, k) + arr[i] + speed - 1) / speed * speed; 
        if(k > 0) // can use skip
            res = min(res, arr[i] + dfs(i-1, k-1));
        
        return dp[i][k] = res;
    }
    
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        n = dist.size();
        this->speed = speed;
        arr = dist;
        
        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        
        for(int k = 0; k <= n; ++k){
            if(dfs(n-1, k) <= 1LL * hoursBefore * speed)
                return k;
        }
        
        return -1;
    }
};
