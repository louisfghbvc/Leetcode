//Impressive. XOR: x ^ x = 0, x ^ 0 = x 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto &x: nums)
            ans ^= x;
        return ans;
    }
};
