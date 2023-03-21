class Solution {
public:
    long long findScore(vector<int>& nums) {
        // goal: get the score, simulate the process
        // idea:
        
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j] || (nums[i] == nums[j] && i < j);
        });
        
        vector<bool> vis(n);
        long ans = 0;
        for (int i: idx) {
            if (vis[i]) continue;
            ans += nums[i];
            vis[i] = true;
            if (i)
                vis[i-1] = true;
            if (i+1 < n)
                vis[i+1] = true;
        }
        return ans;
    }
};
