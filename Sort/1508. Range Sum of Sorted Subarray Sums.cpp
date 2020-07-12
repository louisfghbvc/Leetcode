// Prefix and sort all.
// add it.

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9+7;
        vector<int> arr;
        vector<int> pre(n+1);
        for(int i = 1; i <= n; ++i){
            pre[i] = pre[i-1] + nums[i-1];
            pre[i] %= mod;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= n; ++j){
                arr.push_back(pre[j] - pre[i-1]);
            }
        }
        sort(arr.begin(), arr.end());
        // for(auto &x: arr)
        //     cout << " " << x;
        // cout << endl;
        int res = 0;
        for(int i = left-1; i < right; ++i){
            res += arr[i];
            res %= mod;
        }
        return res;
    }
};
