// mapping the orginal value to operation

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        // idea: unordered_map -> key, value
        
        unordered_map<int, int> mp; // record value -> mp
        for (int i = 0; i < nums.size(); ++i)
            mp[nums[i]] = i;
        
        for (auto &ops: operations) {
            int idx = mp[ops[0]];
            nums[idx] = ops[1];
            mp.erase(ops[0]); // O(1)
            mp[ops[1]] = idx;
        }
        
        return nums;
    }
};
