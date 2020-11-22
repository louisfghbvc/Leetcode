// delete index i, will change parity after i.
// use prefix sum make compute value be O(1). just use sign to reverse parity.
// e.g. 2 1 6 4.
//      + - + - => prefix sum = [2, 1, 7, 3]
// if remove 0. [X] [- + -] => [X] [+ - +] right?
// if remove 1. [+] [X] [+ -] => [+] [X] [- +] right?
// if remove 2. [+ -] [X] [-] => [+ -] [X] [+] right?

// O(N). 
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i= 1; i < n; ++i){
            if(i&1) pre[i] = pre[i-1] - nums[i];
            else pre[i] = pre[i-1] + nums[i];
        }
        
        int cnt = 0;
        if(n >= 2 && pre[n-2] == 0) cnt++;
        if(n >= 2 && pre[n-1] - pre[0] == 0) cnt++;
        for(int i = 1; i+1 < n; ++i){
            int left = pre[i-1];
            int right = -(pre[n-1] - pre[i]);
            if(left + right == 0) cnt++;
        }
        return cnt;
    }
};

// O(N). O(1) Space.
// just record total parity. prefix + suffix
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int sum[2] = {}, n_sum[2] = {}, res = 0;
        for(int i = 0; i < nums.size(); ++i)
            sum[i % 2] += nums[i];
        
        for(int i = 0; i < nums.size(); ++i){
            sum[i % 2] -= nums[i];
            if(sum[0] + n_sum[1] == sum[1] + n_sum[0]) res++;
            n_sum[i % 2] += nums[i];
        }
        
        return res;
    }
};
