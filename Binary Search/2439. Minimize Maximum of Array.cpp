class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        // goal: try to minimize the maximum value
        // idea: binary search the ans
        
        int mx = *max_element(nums.begin(), nums.end());
        
        int n = nums.size();
        auto ok = [&](int x) {
            vector<long> tmp(nums.begin(), nums.end());
            for (int i = n-1; i >= 1; --i) {
                if (tmp[i] >= x) { // need decrease
                    tmp[i-1] += tmp[i]-x;
                }
            }
            return tmp[0] <= x;
        };
        
        int l = 0, r = mx;
        int ans = mx;
        while (l <= r) {
            int mid = (l+r)/2;
            if (ok(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        
        return ans;
    }
};
