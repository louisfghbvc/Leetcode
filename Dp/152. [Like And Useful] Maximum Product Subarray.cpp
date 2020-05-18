// O(N). O(1). One pass. very cool
// maintain a local min and max, when num is neg swap min and max.
// when num is zero maintain min, max nums[i].
// awesome solve.

// another concept is from begin and from back.
// ex: aBcD or aBcDe => lower neg, upper positive.
// can use two pointer. trick.

// but I prefer solution1.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        for(int i = 1, imax = mx, imin = mx; i < n; ++i){
            if(nums[i] < 0) swap(imax, imin);
            imax = max(nums[i], imax*nums[i]);
            imin = min(nums[i], imin*nums[i]);
            mx = max(mx, imax);
        }
        return mx;
    }
};
