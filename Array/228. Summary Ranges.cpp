// O(N). just like sliding window. and compare is continous or not.

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        for(int l = 0, r = 0; r < n; ++r){
            if(r == n-1 || nums[r]+1 != nums[r+1]){
                if(l == r) res.push_back(to_string(nums[l]));
                else res.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
                l = r+1;
            }
        }
        return res;
    }
};
