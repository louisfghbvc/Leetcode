class Solution {
public:

    auto getSizeK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_set<int>> dp(k);
        unordered_map<int, int> first;
        dp[0].insert(0);
        for (int i = 0; i < n; ++i) {
            for (int val: dp[k-1]) {
                if (!first.count(val | nums[i]))
                    first[val | nums[i]] = i+1;
            }
            for (int j = k-2; j >= 0; --j)
                for (int val: dp[j])
                    dp[j+1].insert(val | nums[i]);
        }
        return first;
    }

    int maxValue(vector<int>& nums, int k) {
        // goal: find max value of subsequence size 2*k
        // value:
        // (left OR value) XOR (right OR value)

        // idea:
        // n = 3
        // 10, 01, 11
        // 10 ^ 11

        // OR value non-decreasing, consider all possible is very small
        // can we fix the split index?
        // [0, index-1], [index+1, n]
        // we just make sure left part size is >= k, right part is also >= k

        // we can record the size k
        // base on log trick, the size k of OR val is very small
        // we just enumerate and compute the max!!

        // we need to restore all possible of prefix

        // after looking the solution
        // the preprocessing can improve by using dp, O(n k 8), base log trick
        // and we record the first index, that size is k
        // val -> index
        // after like try to enumrate all mask
        // check

        auto left = getSizeK(nums, k);
        reverse(nums.begin(), nums.end());
        auto right = getSizeK(nums, k);

        int ans = 0;
        int n = nums.size();
        for (auto &[a, i]: left) {
            for (auto &[b, j]: right) {
                if (i+j <= n) // no overlapping
                    ans = max(ans, a^b);
            } 
        }

        return ans;
    }
};
