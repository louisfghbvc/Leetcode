class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        // goal: find the sum of all good subsequence
        // good seq: adj dif by 1
        
        // idea:
        // [1,2,1,1,2]
        //  ^ 1     2
        
        // think about dp
        // do reverse
        // x => try to add previous x-1, 
        // dp[i] += dp[j], a[i]=a[j]-1/a[j]+1
        
        // think distribution
        // [1,2,1,3,1,2]
        //  x will increase a[x-1], a[x+1] sum        
        
        // dp[i]: ending at index i, number of subsequence
        // two dp, first is sum, second is cnt
        
        // 1,2,1
        // [1], s=1,c=1
        // [1,2] [2], s=5,c=2
        // [1,2,1], [2,1], [1], s=5+c*x, c=3
        
        // what is duplicate?
        // [10,10,1,9]
        // [10]
        // [10]
        // [1]
        // [10,9],[10,9],[9]
        
        int mod = 1e9+7;
        unordered_map<int, long> sum, cnt;
        
        long ans = 0;
        for (long x: nums) {
            long prev_sum = sum[x-1] + sum[x+1];
            long prev_cnt = cnt[x-1] + cnt[x+1];
            cnt[x] += prev_cnt+1;
            cnt[x] %= mod;
            
            long add = prev_sum + (prev_cnt+1)*x;
            ans = (ans + add) % mod;
            sum[x] += add;
            sum[x] %= mod;
        }
        return ans;
    }
};
