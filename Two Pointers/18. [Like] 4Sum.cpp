// First sort, and like 3 sum. fix one.
// 3 sum can fix one then, do two sum.
// remember duplicate.
// O(N^3)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i){
            int new_target = target - nums[i];
            for(int j = i + 1; j < nums.size(); ++j){
                int l = j + 1, r = nums.size() - 1;
                while(l < r){
                    int val1 = nums[l], val2 = nums[r];
                    if(nums[j] + nums[l] + nums[r] < new_target){
                        l++;
                    }
                    else if(nums[j] + nums[l] + nums[r] > new_target){
                        r--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < nums.size() && nums[l] == val1) l++;
                        while(r >= 0 && nums[r] == val2) r--;
                    }
                    
                }
                while(j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
