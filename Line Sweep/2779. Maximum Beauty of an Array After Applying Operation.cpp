class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // goal: find the maximum subsequence that is beauty
        
        // idea:
        // make nums[i] to interval
        // interval maximum problem
        // find the most overlap values
        
        map<int, int> cnt;
        for (int x: nums) {
            cnt[x-k]++;
            cnt[x+k+1]--;
        }
        
        int ans = 0;
        int f = 0;
        for (auto &[k, v]: cnt) {
            f += v;
            ans = max(f, ans);
        }
        
        return ans;
    }
};
