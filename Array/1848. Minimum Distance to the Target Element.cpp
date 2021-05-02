class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mx = 1e9;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == target)
                mx = min(mx, abs(start - i));
        }
        return mx;
    }
};
