class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        while (nums.size() > 1) {
            int n = nums.size();
            vector<int> tmp;
            for (int i = 0, cnt = 0; i < n; i += 2, cnt++) {
                if (cnt % 2 == 0)
                    tmp.push_back(min(nums[i], nums[i+1]));
                else
                    tmp.push_back(max(nums[i], nums[i+1]));
            }
            nums = tmp;
        }
        
        return nums[0];
    }
};
