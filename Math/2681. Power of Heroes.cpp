class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        // goal: find the sum of power of all subset
        // idea:
        // array order no matter
        // 1,2,  4
        //   c=2^2+p + c=0
        //         p=0
        //.  p=4^2 
        // 
        
        // 1^2+2^2+4^2 * power(2, j-i-1) = 1+4+16 = 21+16=37
        // 2 * (2^2+4^2) = 2*20 = 40
        // 4* 4^2 = 64
        // 141
        
        // we sort and double the sum
        
        sort(nums.rbegin(), nums.rend());
        long ans = 0;
        int mod = 1e9+7;
        
        long prev = 0;
        for (long mn: nums) {
            long add = mn*mn % mod;
            long cur = mn * (add+prev) % mod; 
            ans = (ans + cur) % mod;
            prev = (prev * 2 % mod + add) % mod;
        }
        
        return ans;
    }
};
