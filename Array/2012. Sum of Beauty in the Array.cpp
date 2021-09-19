// Prefix and suffix O(N).

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> suf(n);
        suf.back() = nums.back();
        for(int i = n-2; i >= 0; --i)
            suf[i] = min(suf[i+1], nums[i]);
        
        int res = 0;
        int prev = nums[0];
        for(int i = 1; i+1 < n; ++i){
            if(prev < nums[i] && nums[i] < suf[i+1]) res += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) res += 1;
            prev = max(nums[i], prev);
        }
        return res;
    }
};
