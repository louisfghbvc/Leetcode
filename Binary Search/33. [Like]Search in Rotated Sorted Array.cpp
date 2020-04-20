//Prefer like this, just 2 case. left part or right part
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target) return mid;
            
            // left part increasing
            //must use "<=" make sure target is left part
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target < nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            // right part increasing
            else{
                if(nums[r] >= target && target > nums[mid]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }

        }
        return -1;
    }
};

//Very trick. hard to understand
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;

            int num = (nums[mid] < nums[0]) == (target < nums[0]) 
                    ? nums[mid] 
                    : target < nums[0] ? -INT_MAX : INT_MAX; 

            if(num < target){
                l = mid + 1;
            }
            else if(num > target){
                r = mid - 1;
            }
            else return mid;
        }
        return -1;
    }
};
