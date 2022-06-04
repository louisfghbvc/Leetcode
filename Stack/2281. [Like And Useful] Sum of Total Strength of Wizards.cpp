class Solution {
public:
    
    const int mod = 1e9+7;
    
    int totalStrength(vector<int>& nums) {
        // goal: find the sum of all subarray
        // where product of min and sum of subarray
        
        // idea: O(N^2) -> better approach is. that from each minimum find the distribution of subarray        
        // question: how to handle the subarray sum?
        
        // [a X X i X X X b]
        // a: prev smaller, b: next smaller
        // index range: x = i-a, y = b-i
        // all left sum: (nums[a+1]*1+nums[a+2]*2) * y
        // all right sum: (nums[i+1]*3+...nums[i+3]*1) * x
        // and nums[i] * x * y
        // ans will add all of them * nums[i]
        
        // left sum: nums[a+1]*1+nums[a+2]*2
        // let pre2[i] = sum of nums[i]*i
        // pre2[i-1] - pre2[a]:
        // = nums[a+1]*(a+1) + nums[a+2]*(a+2)
        // = what we want + sum of num[a+1:i-1] * a
        
        // right sum:
        // sum of num[a+1:i-1]*b - (pre2[b-1]-pre2[i])
        
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        
        vector<long> pre(n+2), pre2(n+2); // [0, ...., 0]
        
        for (int i = 1; i <= n; ++i) {
            pre[i] = (pre[i-1] + nums[i]) % mod;
            pre2[i] = (pre2[i-1] + (long)nums[i]*i) % mod;
        }
        
        vector<int> left(n+2), right(n+2, n+1); // left: prev idx <= nums[i], right: next idx < nums[i]
        
        // build the left, right array
        stack<int> st;
        for (int i = 1; i <= n; ++i) {
            while (st.size() && nums[st.top()] > nums[i]) {
                right[st.top()] = i;
                st.pop();
            }
            if (st.size())
                left[i] = st.top();
            st.push(i);
        }
        
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int a = left[i], b = right[i];
            int x = i-a, y = b-i;
            long left_sum = ((pre2[i-1] - pre2[a]) % mod - (pre[i-1] - pre[a]) * a % mod + mod) % mod;
            long right_sum = (((pre[b-1] - pre[i]) * b % mod - (pre2[b-1] - pre2[i]) % mod) + mod) % mod;
            long mid = (long)nums[i] * x * y % mod;
            ans = (ans + (left_sum * y % mod + right_sum * x % mod + mid) * nums[i] % mod) % mod;
        }
        
        return ans;
    }
};
