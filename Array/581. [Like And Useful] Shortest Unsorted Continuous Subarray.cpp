// O(N). Super cool!!.
// find right position, is small than max, cuz if x < max. must swap.
// find again reverse same as left position. if x > min, must swap
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = n, r = 0;
        int mn = 1e6, mx = -1e6;
        for(int i = 0; i < n; ++i){
            mx = max(mx, nums[i]);
            if(nums[i] < mx)
                r = i;
        }
        for(int i = n-1; i >= 0; --i){
            mn = min(mn, nums[i]);
            if(nums[i] > mn)
                l = i;
        }
        return max(0, r-l+1);
    }
};

// extra space, use a sorted array to compare. not equal index must be sort. maintain window size
// O(NlogN)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int l = n, r = 0;
        for(int i = 0; i < n; ++i){
            if(tmp[i] != nums[i]){
                l = min(l, i);
                r = i;
            }
        }
        return max(0, r-l+1);
    }
};
