// Simple O(N).

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res;
        int xr = 0;
        for(int x: nums){
            xr ^= x;
            int mx_xor = xr | ((1<<maximumBit)-1);
            res.push_back(mx_xor ^ xr);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
