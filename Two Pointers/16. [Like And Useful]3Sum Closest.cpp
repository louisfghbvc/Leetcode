//12ms 8.6MB
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, opt = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(opt > abs(sum - target)){
                    opt = abs(sum - target);
                    ans = sum;
                }
                if(sum < target){
                    l++;
                }
                else
                    r--;
            }
        }
        return ans;
    }
};
