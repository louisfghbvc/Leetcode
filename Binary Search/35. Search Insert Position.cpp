// Simple, Just Binary Search value.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int id = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return id;
    }
};
