// prefix + suffix.
// prefix first
// and go suffix. just 3 case. from begin. from back or middle.
// binary search. prefix sum.
// O(NlogN).

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pre(n+1);
        int res = 1e9;
        for(int i = 0; i < n; ++i){
            pre[i+1] = pre[i] + nums[i];
            if(pre[i+1] == x) res = min(res, i+1);
        }
        
        int suf = 0;
        for(int i = n-1; i >= 0; --i){
            auto p = lower_bound(pre.begin(), pre.end(), x-suf);
            if(p != pre.end()){
                int v = *p;
                int d = p-pre.begin();
                if(x-suf >= 0 && v == x-suf && d <= i) res = min(res, n-i-1 + d);
            }
            suf += nums[i];
            if(suf == x) res = min(res, n-i); 
        }
        
        return res >= 1e9 ? -1: res;
    }
};

// O(N). sliding window. O(1) space. like two sum strategy.
// equal to find the longest subarray. total sum - x.
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0) - x;
        if(sum < 0) return -1;
        if(sum == 0) return nums.size();
        
        int res = -1, l = 0, cur = 0;
        for(int r = 0; r < n; ++r){
            cur += nums[r];
            while(cur >= sum){
                if(cur == sum) res = max(res, r-l+1);
                cur -= nums[l++];
            }
        }
        
        return res < 0 ? -1: n-res;
    }
};
