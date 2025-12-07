class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        auto f = [&](int x) {
            long val = 0;
            while (x) {
                val = val * 2 + x % 2;
                x >>= 1;
            }    
            return val;
        };
        sort(nums.begin(), nums.end(), [&](int x, int y) {
            if (f(x) == f(y))
                return x < y;
            return f(x) < f(y);    
        });
        return nums;
    }
};
