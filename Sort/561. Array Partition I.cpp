// Sort and add first. that can make min max.

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n-1; i+=2){
            res += nums[i];
        }
        return res;
    }
};
