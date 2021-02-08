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

// O(KNlogN) upper_bound trick... a is val, b is forward iterator.
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> arr;
    int n;
    
    int dfs(int i, int k){
        if(k == 0 || i >= n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int j = upper_bound(arr.begin()+i+1, arr.end(), vector<int>{0, arr[i][1], 0}, [](auto &a, auto &b){
          return a[1] < b[0];  
        }) - arr.begin();
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

// Bottom up dp. rename time to continous. and use it as graph. and dp.
// the i means cur time. so should be i+1, since event time is inclusive.
// So from j-1.

class Solution {
public:
    typedef pair<int, int> ii;
    int maxValue(vector<vector<int>>& events, int k) {
        vector<int> pos;
        for(auto &e: events){
            pos.push_back(e[0]);
            pos.push_back(e[1]);
        }
        sort(pos.begin(), pos.end());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        
        int n = pos.size();
        vector<vector<ii>> g(n);
        for(auto&e: events){
            e[0] = lower_bound(pos.begin(), pos.end(), e[0]) - pos.begin();
            e[1] = lower_bound(pos.begin(), pos.end(), e[1]) - pos.begin();
            g[e[1]].push_back({e[0], e[2]});
        }
        
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        for(int i = 0; i < n; ++i){
            dp[i+1] = dp[i];
            for(int j = 1; j <= k; ++j){
                dp[i+1][j] = max(dp[i+1][j], dp[i+1][j-1]);
                for(auto &[from, val]: g[i]){
                    dp[i+1][j] = max(dp[i+1][j], dp[from][j-1] + val);
                }
            }
        }
        
        return dp[n][k];
    }
};
