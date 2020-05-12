// O(logN). mid^1 = if even mid+1 or mid-1
// then binary search. finally ans is l.
// trick is mid^1
// if 0 0 1 1 2 2 3, 
//        ^ ^       .search right.
// if 1 2 2 3 3 4 4 
//        ^ ^       .search left.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] == nums[mid^1]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return nums[l];
    }
};

// O(N) XOR solution x^0 = x, x^x = 0
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = 0;
        for(const auto n: nums) x ^= n;
        return x;
    }
};
