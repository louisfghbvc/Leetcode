class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // goal: find the power of all subarray size is k
        // power: if array is consecutive and sort

        // idea:
        // sliding window
        // but how to check window is sorted?
        // we can consider the nums[i]==nums[i-1]+1, use a cnt

        int n = nums.size();
        vector<int> res;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i && nums[i] == nums[i-1]+1) cnt++;
            if (i >= k-1) {
                //  record ans
                if (cnt == k-1) {
                    res.push_back(nums[i]);
                }
                else {
                    res.push_back(-1);
                }
                // remove
                if (i-(k-1)+1 < n && nums[i-(k-1)+1] == nums[i-(k-1)]+1) cnt--;
            }
        }

        return res;
    }
};
