// BS. O(logN)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] <= nums[mid+1]){
                l = mid+1;
            }
            else{ // make sure mid is bigger than next. so this may be the peak
                r = mid;
            }
        }
        return l;
    }
};
