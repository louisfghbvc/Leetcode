// O(NlogN). Sparse table. Divide and Conquer. RMQ.
// Main idea is I want delete minimum.

class Solution {
public:
    const int mod = 1e9+7;
    int rmq[100005][17];
    
    int query(const vector<int> &nums, int i, int j){
        int len = log2(j-i+1);
        if(nums[rmq[i][len]] < nums[rmq[j - (1<<len) + 1][len]])
            return rmq[i][len];
        return rmq[j - (1<<len) + 1][len];
    }
    
    vector<long> pre;
    long MS(const vector<int> &nums, int l, int r){
        if(l > r) return 0;
        int i = query(nums, l, r);
        long sum = pre[r+1] - pre[l];
        return max({(long)nums[i] * sum, MS(nums, l, i-1), MS(nums, i+1, r)});
    }
    
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        
        pre = vector<long>(n+1);
        for(int i = 1; i <= n; ++i)
            pre[i] = pre[i-1] + nums[i-1];
        
        for(int i = 0; i < n; ++i)
            rmq[i][0] = i;
        for(int j = 1; 1<<j <= n; ++j){
            for(int i = 0; i + ((1<<j) - 1) < n; ++i){
                // rmq[i][j] = min(rmq[i][j-1], rmq[i + 1<<(j-1)][j-1]; 
                if(nums[rmq[i][j-1]] < nums[rmq[i + (1<<(j-1))][j-1]])
                    rmq[i][j] = rmq[i][j-1];
                else
                    rmq[i][j] = rmq[i + (1<<(j-1))][j-1];
            }
        }
        
        return MS(nums, 0, n-1) % mod;
    }
};
