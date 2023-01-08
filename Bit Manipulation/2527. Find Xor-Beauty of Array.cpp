class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        // goal: find xor beauty
        // effective: ((nums[i] | nums[j]) & nums[k])
        // idea:
        
        // 1. seperate the bit
        // [001, 100]
        // calculate the number of bit is set
        // i,j,k
        // 0,0,0
        // 1,0,1
        //     ^
        // cal these pattern
        // 1,1 1
        // 0,1 1
        // 1,0 1
        
        // 1^1 = 0
        // 1^1^1 = 1(odd)
        
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            long cnt[2] = {}; // zero, one;
            for (int x: nums)
                cnt[(x >> i & 1)]++;
            long total_num = 0;
            total_num += cnt[1] * cnt[1] * cnt[1];
            total_num += cnt[1] * cnt[0] * cnt[1];
            total_num += cnt[0] * cnt[1] * cnt[1];
            if (total_num & 1)
                ans |= 1<<i;
        }
        return ans;
    }
};
