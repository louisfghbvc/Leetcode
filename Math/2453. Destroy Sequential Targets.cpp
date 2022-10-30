class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        // goal: find the minimum value, with destroy the maximum target, only can erase one sequence
        // idea: 
        // (nums[i] + c*space) % space
        
        // find the mod value maximum, and the minimum mod value
        // min mod -> minimum number, start point
        
        unordered_map<int, int> cnt;
        unordered_map<int, int> mn;
        
        int mx = 0;
        for (int x: nums) {
            mx = max(mx, ++cnt[x % space]);
            if (mn.count(x%space))
                mn[x%space] = min(mn[x%space], x);
            else
                mn[x%space] = x;
        }
        
        int ans = INT_MAX;
        for (auto &[mod, fre]: cnt) {
            if (fre == mx)
                ans = min(ans, mn[mod]);
        }
        return ans;
    }
};
