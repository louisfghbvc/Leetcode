//104ms 14.6MB
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int key = -nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum < key)
                    l++;
                else if(sum > key)
                    r--;
                else{
                    int t1 = nums[l], t2 = nums[r];
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && t1 == nums[l]) l++; // dup 2
                    while(l < r && t2 == nums[r]) r--; // dup 3
                }
            }  
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++; // dup1     
        }
        return ans;
    }
};
