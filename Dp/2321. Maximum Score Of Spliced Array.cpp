class Solution {
public:
    
    int helper(vector<int> &nums1, vector<int> &nums2) {
        int base = accumulate(nums1.begin(), nums1.end(), 0);
        
        vector<int> arr;
        for (int i = 0; i < nums1.size(); ++i) {
            arr.push_back(nums2[i] - nums1[i]);
        }
        
        int mx = 0;
        int sum = 0;
        for (int x: arr) {
            sum = max(x, sum+x);
            mx = max(mx, sum);
        }
        
        return base + mx;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        // goal: max(sum(nums1), sum(nums2))
        // operation: swap a [l:r] in nums1 and nums2
        // idea: dp
        // maximum subarray
        
        // [60,60,60],    [10,90,10]
        // -50 30 -50      50 
        // 180+30
        
        return max(helper(nums1, nums2), helper(nums2, nums1));
    }
};
