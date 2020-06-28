// Same as two sum, and min and max range.
// then i~j, choose i+1~j => pow(2, j-i)
// and precalculate 2^n mod 1e9+7
// the modulo is very cool.
// example [3,5,6,7]
// so 3 ~ 6
// fix 3, u can choose 5,6
// think as bit so 2^2 choose. add it to res, remember mod
// Like sliding window, but more cool. shrink

class Solution {
public:
    const int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        
        vector<int> pow(n, 1);
        for(int i = 1; i < n; ++i)
            pow[i] = pow[i-1]*2 %mod;
        
        int l = 0, r = n-1;
        while(l <= r){
            if(nums[l] + nums[r] > target){
                r--;
            }
            else{
                res = (res+pow[r-l])%mod;
                l++;
            }
        }
        
        return res;
    }
};
