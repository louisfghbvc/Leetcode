// O(KNN). dp... think it as greedy but it has value...
// choose or not choose... dp choose max. so no need to worry what happen back back.
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> arr;
    int n;
    
    int dfs(int i, int k){
        if(k == 0 || i >= n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int j;
        for(j = i+1; j < n; ++j) if(arr[i][1] < arr[j][0]) break;
        return dp[i][k] = max(dfs(i+1, k), arr[i][2] + dfs(j, k-1));
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());
        arr = events;
        dp = vector<vector<int>>(n, vector<int>(k+1, -1));
        
        return dfs(0, k);
    }
};

// O(KNlogN) upper_bound trick...
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> arr;
    int n;
    
    int dfs(int i, int k){
        if(k == 0 || i >= n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int j;
        for(j = i+1; j < n; ++j) if(arr[i][1] < arr[j][0]) break;
        return dp[i][k] = max(dfs(i+1, k), arr[i][2] + dfs(j, k-1));
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());
        arr = events;
        dp = vector<vector<int>>(n, vector<int>(k+1, -1));
        
        return dfs(0, k);
    }
};
