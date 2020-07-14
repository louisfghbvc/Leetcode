class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<pair<int, int>> v;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; ++i){
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; ++i){
            int id = v[i].second;
            int l = max(id - d, 0), r = min(n - 1, id + d);
            for(int j = id - 1; j >= l && arr[id] > arr[j]; --j){
                dp[id] = max(dp[id], 1 + dp[j]); 
            }
            for(int j = id + 1; j <= r && arr[id] > arr[j]; ++j){
                dp[id] = max(dp[id], 1 + dp[j]); 
            }
        }
        int mx = -1;
        for(auto x : dp)
            mx = max(x, mx);
        return mx;
    }
}
