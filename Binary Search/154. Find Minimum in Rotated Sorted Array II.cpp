// O(N). BS, if mid > high means low are right part.
// or left part.
// if same not sure left or right. so right--.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int m = l + (r - l)/2;
            if(nums[m] > nums[r]) l = m + 1;
            else if(nums[m] < nums[r]) r = m;
            else r--;
        }
        return nums[l];
    }
};


// O(N). Brute Force
class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};
