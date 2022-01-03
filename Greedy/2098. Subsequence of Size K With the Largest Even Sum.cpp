// Greedy, and observe that sort will not influence the sequence here.
// O(NlogN)

class Solution {
public:
    
    // top-1
    long top(vector<long>& pre, int k){
        assert(k < pre.size());
        return pre[k];
    }
    
    long long largestEvenSum(vector<int>& nums, int k) {
        long res = -1;
        
        sort(nums.rbegin(), nums.rend());
        
        // k = 5, 1 even + 4 odd
        // k = 5, 3 even + 2 ood
        // k = 5, 5 even
        //        0      + 4 odd
        // k = 4, 2 even + 2 odd
        //        4 even + 0 odd
        
        vector<int> even, odd;
        for(int x: nums){
            if(x & 1) odd.push_back(x);
            else even.push_back(x);
        }
        vector<long> pre_even(1), pre_odd(1);
        for(int x: even)
            pre_even.push_back(pre_even.back() + x);
        for(int x: odd)
            pre_odd.push_back(pre_odd.back() + x);
        
        int even_cnt = k % 2;
        for(int i = even_cnt; i <= k; i += 2){
            int odd_cnt = k - i;
            if(pre_even.size() <= i || pre_odd.size() <= odd_cnt) continue;
            res = max(res, top(pre_even, i) + top(pre_odd, odd_cnt));
        }
        
        return res;
    }
};


// Concise. O(N)
class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k, nums.end(), greater<>());
        long sum = accumulate(nums.begin(), nums.begin() + k, 0L), res = -1;
        if(sum % 2 == 0) return sum;
        
        int min_k[2] = {INT_MAX, INT_MAX};
        for(int i = 0; i < k; ++i)
            min_k[nums[i] % 2] = min(min_k[nums[i] % 2], nums[i]);
        for(int i = k; i < nums.size(); ++i)
            res = max(res, sum - min_k[!(nums[i] % 2)] + nums[i]);
        
        return res;
    }
};
