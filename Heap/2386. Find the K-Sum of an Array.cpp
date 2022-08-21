class Solution {
public:
    
    typedef pair<long, int> ii;
    
    long long kSum(vector<int>& nums, int k) {
        // goal: find the kth largest subsequence sum
        // idea: starting from largest sum
        // what is the next largest value
        
        long sum = 0;
        for (int x: nums)
            if (x > 0)
                sum += x;
        
        // convert to positive
        for (int &x: nums) {
            if (x < 0)
                x = -x;
        }
    
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        priority_queue<ii, vector<ii>, greater<ii>> pq; // min heap
        if (k == 1) return sum; // largest
        
        pq.push({nums[0], 0});
        for (int i = 2; i < k; ++i) {
            auto [val, idx] = pq.top(); pq.pop();
            if (idx+1 < n) { // forward to next subsequence
                pq.push({val + nums[idx+1], idx+1}); // (...i-1, i, i+1)
                pq.push({val + nums[idx+1] - nums[idx], idx+1}); // (...i-1, i+1)
            }
        }
        
        return sum - pq.top().first;
    }
};
