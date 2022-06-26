class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        // goal: maximum tht number XOR value  
        // idea: erase odd XOR
        // 011, 010, 100, 110
        // operation -> erase one bit
    
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            int cnt = 0;
            for (int x: nums) {
                if (x >> i & 1)
                    cnt++;
            }
            if (cnt)
                ans |= 1<<i;
        }
        return ans;
    }
};
