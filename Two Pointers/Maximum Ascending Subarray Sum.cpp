// maximum subarray dp. O(N).

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mx = nums[0], sum = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; ++i){
            sum = nums[i] > nums[i-1] ? sum+nums[i] : nums[i];
            mx = max(mx, sum);
        }
        return mx;
    }
};

// O(N^2) BF.

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int sum = nums[i];
            for(int j = i+1; j < n; ++j){
                if(nums[j] > nums[j-1]) sum += nums[j];
                else break;
            }
            mx = max(mx, sum);
        }
        return mx;
    }
};
