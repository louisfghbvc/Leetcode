// O(logN). BS. General
// convert nums to nums[ nums[i] <= nums[-1] ] = 1, else 0
// 1 2 3 4 0 -> 0 0 0 0 1
// 2 3 4 0 1 -> 0 0 0 1 1
// ...
// 0 1 2 3 4 -> 1 1 1 1 1
class Solution {
public:
    int findMin(vector<int>& nums) {
        // convert to 0 1 problem
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] <= nums.back()){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return nums[ans];
    }
};
