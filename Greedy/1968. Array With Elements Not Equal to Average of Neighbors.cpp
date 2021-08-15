// Greedy. Sort and put big and small alternate.
class Solution {
public:

    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> res;
        for(int i = 0, j = nums.size()/2; i < nums.size()/2; ++i, ++j){
            res.push_back(nums[j]);
            res.push_back(nums[i]);
        }
        if(nums.size() % 2) res.push_back(nums.back());
        return res;
    }
};
