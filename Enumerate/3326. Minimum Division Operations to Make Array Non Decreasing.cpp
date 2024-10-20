class Solution {
public:
    int minOperations(vector<int>& nums) {
        // goal: find the minimum operations to make array non-decreasing
        // each time we can divide a factor
        
        // idea:
        // if prime, can't divide
        
        // if nums[i-1] <= nums[i]:
        // we just make sure if we have factor that is greater
        // 
        
        // if we do it reverse
        // x x x x y
        
        int n = nums.size();
        
        int ans = 0;
        for (int i = n-2; i >= 0; --i) {
            if (nums[i] > nums[i+1]) {
                // change nums[i]
                int sq = sqrt(nums[i]);
                int mx = -1;
                for (int p = 2; p <= sq; ++p) {
                    if (nums[i] % p == 0) {
                        int a = p, b = nums[i]/p;
                        if (a <= nums[i+1]) {
                            mx = max(a, mx);
                        }
                        if (b <= nums[i+1]) {
                            mx = max(b, mx);
                        }
                    }
                }
                if (mx == -1) return -1;
                nums[i] = mx;
                ans++;
            }
        }
        
        return ans;
    }
};
