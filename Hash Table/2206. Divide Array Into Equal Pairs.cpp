// Simple
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // goal: divide nums into n pairs
        // idea: use a counter to record the frequency
        // go through the counter to see all element is even
        
        unordered_map<int, int> mp;
        for (int x: nums)
            mp[x]++;
        
        for (auto &[k, v]: mp) {
            if (v % 2) return false;
        }
        return true;
    }
};
