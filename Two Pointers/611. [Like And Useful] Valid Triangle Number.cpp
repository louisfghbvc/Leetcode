// Tricky Three sum tweak. O(N^2). O(1) space

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int k = 2; k < n; ++k){
            int l = 0, r = k - 1;
            while(l < r){
                if(nums[l] + nums[r] > nums[k]){ // l can go to r-1, and then we want smaller.
                    res += r - l;
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return res;
    }
};
