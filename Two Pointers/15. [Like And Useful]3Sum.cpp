// 96ms 19.5MB
// So fix x, and sort first.
// if sort, u can use greedy two pointer to handle
// O(N^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int target = -nums[i], l = i+1, r = n-1;
            while(l < r){
                int sum = nums[l]+nums[r];
                if(sum < target) l++;
                else if(sum > target) r--;
                else{
                    int t1 = nums[l], t2 = nums[r];
                    res.push_back({-target, nums[l], nums[r]});
                    while(l < r && nums[l] == t1) l++;
                    while(l < r && nums[r] == t2) r--;
                }
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};
