// just a joke ?
// O(N).
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int x: nums) if(x == target) return true;
        return false;
    }
};

// avg. O(logN). 
// a rotated array feature is really simple. like two increasing seq.
// just check which is a correct interval can search. 
// duplicate case just move left or right pointer.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target) return true;
            if(nums[l] < nums[mid]){
                if(nums[l] <= target && nums[mid] > target) r = mid-1;
                else l = mid+1;
            }
            else if (nums[mid] < nums[r]){
                if(nums[mid] < target && nums[r] >= target) l = mid+1;
                else r = mid-1;
            }
            else{
                if(nums[l] == nums[mid]) l++;
                if(nums[r] == nums[mid]) r--;
            }
        }
        return false;
    }
};
