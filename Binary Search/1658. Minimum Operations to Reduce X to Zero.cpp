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
