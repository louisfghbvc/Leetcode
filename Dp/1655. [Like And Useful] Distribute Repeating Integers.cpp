// m == 10. n == 50. backtracking.
// O(?) exponential time.
class Solution {
public:
    vector<int> arr;
    vector<int> qt;
    bool dfs(int i){
        if(i >= qt.size()) return true;
        for(int j = 0; j < arr.size(); ++j){
            if(arr[j] >= qt[i]){
                arr[j] -= qt[i];
                if(dfs(i+1)) return true;
                arr[j] += qt[i];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for(auto &x: nums) mp[x]++;
        for(auto &[a, b]: mp) arr.push_back(b);
        sort(arr.rbegin(), arr.rend());
        qt = quantity;
        sort(qt.rbegin(), qt.rend());
        return dfs(0);
    }
};

// Dp. Top down. slow. O(n4^m?)
class Solution {
public:
    vector<int> arr;
    vector<int> qt;
    int dp[55][1024];
    int n, m;
    bool dfs(int i, int mask){
        if(mask == (1<<m)-1) return 1;
        if(i == n) return 0;
        if(dp[i][mask] != -1) return dp[i][mask];
        
        bool res = dfs(i+1, mask);
        for(int j = 0; j < (1<<m); ++j){
            if(mask != (mask&j)) continue;
            int n_mask = mask;
            int sum = 0;
            for(int k = 0; k < m; ++k){
                if(mask&(1<<k)) continue;
                if(j&(1<<k)){
                    sum += qt[k];
                    n_mask |= (1<<k);
                }
            }
            if(sum <= arr[i])
                res |= dfs(i+1, n_mask);
        }
        
        return dp[i][mask] = res;
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for(auto &x: nums) mp[x]++;
        for(auto &[a, b]: mp) arr.push_back(b);
        qt = quantity;
        
        memset(dp, -1, sizeof dp);
        n = arr.size();
        m = qt.size();
        
        return dfs(0, 0);
    }
};
