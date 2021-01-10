// use hash set is smart!
// avoid duplicate arr sum.
class Solution {
public:
    int tar;
    int col[17];
    vector<int> arr;
    bool dfs(int i, int k){
        if(i == arr.size()) return true;
        unordered_set<int> vis;
        for(int j = 0; j < k; ++j){
            if(vis.count(col[j])) continue;
            if(col[j]+arr[i] <= tar){
                vis.insert(col[j]);
                col[j] += arr[i];
                if(dfs(i+1, k)) return true;
                col[j] -= arr[i];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1) return true;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot % k) return false;
        tar = tot/k;
        arr = nums;
        sort(arr.rbegin(), arr.rend());
        return dfs(0, k);
    }
};

// Dp. use mod, very smart.
// O(N2^N)
class Solution {
public:
    int dp[(1<<16)+5];
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot % k) return false;
        int tar = tot / k;
        
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        int n = nums.size();
        for(int S = 0; S < 1<<n; ++S){
            if(dp[S] == -1) continue;
            for(int i = 0; i < n; ++i){
                if(!(S>>i&1) && dp[S]+nums[i] <= tar){ // choose not set in mask: S
                    dp[S|(1<<i)] = (dp[S] + nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};
