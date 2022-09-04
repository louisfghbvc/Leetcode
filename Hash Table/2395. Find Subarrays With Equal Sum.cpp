class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        // idea: use hashset to record the length2 sum
        // TC: O(N), SC: O(N)
        
        int n = nums.size();
        unordered_set<int> st;
        
        for (int i = 1; i < n; ++i) {
            // {iterator, success insert to the set or not}
            if (!st.insert(nums[i]+nums[i-1]).second) return true;
        }
        
        return false;
    }
};
