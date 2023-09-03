class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        // goal: find the maximum sum of all almost subarray
        
        // distinct pairwise element at least m
        // m <= k <= nums.size()
        
        // idea:
        // subarray is continous
        // when add a number, pairs += length - fre[x]
        // [|2,2,7,3|,1,7]
        
        // 1,2,1,2,1,2,1, k=3, m=3
        // 1,2,1
        // p=1
        
        int n = nums.size();
        
        unordered_map<int, int> fre;
        long sum = 0;
        long ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            sum += nums[i];
            fre[nums[i]]++;
            if (i >= k-1) {
                if (fre.size() >= m)
                    ans = max(ans, sum);
                sum -= nums[j];
                if (--fre[nums[j]] == 0)
                    fre.erase(nums[j]);
                j++;
            }
        }
        
        return ans;
    }
};
