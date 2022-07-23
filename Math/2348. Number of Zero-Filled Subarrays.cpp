class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        // idea: math, calculate the length
        
        long res = 0;
        
        int cnt = 0;
        for (int x: nums) {
            if (x == 0)
                cnt++;
            else 
                cnt = 0;
            res += cnt;
        }
        
        return res;
    }
};
