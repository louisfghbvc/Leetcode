// Simple Sliding Window O(N)
// we can not maintain window size. because that can be ans
// of course, maintain window size flag > 1 means, there is bigger than 1 zero. shrink

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        int flag = 0;
        for(int r = 0, l = 0; r < n; ++r){
            flag += (nums[r] == 0);
            while(flag > 1)
                flag -= (nums[l++] == 0);
            mx = max(mx, r-l+1);
        }        
        return mx-1;
    }
};
