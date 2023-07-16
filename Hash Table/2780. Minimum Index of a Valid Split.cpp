class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // goal: find the equal major element, in left right subarray
        
        // idea:
        // enumerate all index
        // left[0:i], right[i+1:n-1]
        // count the frequency of major
        // prefix fre, suff fre
        
        unordered_map<int, int> cnt;
        for (auto &x: nums) cnt[x]++;
        
        int mx = 0;
        int mx_i = 0; // major
        for (auto &[k, f]: cnt) {
            if (f > mx) {
                mx = f;
                mx_i = k;
            }
        }
        
        int total = cnt[mx_i];
        int pre = 0;
        int n = nums.size();
        for (int i = 0; i+1 < n; ++i) {
            pre += nums[i] == mx_i;
            total -= nums[i] == mx_i;
            int left = i+1;
            int right = n-i-1;
            if (pre * 2 > left && total * 2 > right)
                return i;
        }
        
        return -1;
    }
};
