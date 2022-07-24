// TC: O(NlogA).

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        // goal: is sum of numbers bits
        
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> cnt(31);
        for (int x: st) {
            cnt[__builtin_popcount(x)]++;
        }
        
        long res = 0;
        for (int x: st) {
            int bit_cnt = __builtin_popcount(x);
            for (int i = 0; i <= 30; ++i) {
                if (bit_cnt + i >= k)
                    res += cnt[i];
            }
        }
        
        return res;
    }
};
