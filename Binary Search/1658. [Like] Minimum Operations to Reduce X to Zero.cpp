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
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot == x) return n;
        if(x > tot) return -1;
        
        int res = -1, tar = tot-x, sum = 0;
        for(int r = 0, l = 0; r < n; ++r){
            sum += nums[r];
            while(sum > tar) sum -= nums[l++];
            if(sum == tar) res = max(r-l+1, res);
        }
        
        return res < 0 ? -1 : n - res;
    }
};

// prefix map since we need to find tot - x.
// use sum - l = tot - x. let tot - x = t.
// so just same as find sum - t. two sum tweak.
// O(N). Space O(N).
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        for(int v: nums) target += v;
        if(!target) return nums.size();
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int res = -1, sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(mp.count(sum - target))
                res = max(res, i - mp[sum - target]);
            mp[sum] = i;
        }
        
        
        return res < 0 ? -1 : nums.size()-res;
    }
};

