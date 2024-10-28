class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // goal: find the longest square streak

        // idea:
        // we just sort the nums
        // using the hash map
        // for each x => check x*x existed, if x is square number

        ranges::sort(nums);

        unordered_map<int, int> dp;
        int ans = 0;
        for (int x: nums) {
            int sq = sqrt(x);
            if (sq * sq == x) {
                dp[x] = dp[sq] + 1;
            }
            else {
                dp[x] = 1;
            }
            ans = max(ans, dp[x]);
        }

        if (ans == 1) return -1;
        return ans;
    }
};

// Order is no need, we can just unordered set, start from min element!!
// TC: O(n)
class Solution {
public:
    
    bool isSq(int x) {
        int sq = sqrt(x);
        return sq*sq == x;
    }
    
    int longestSquareStreak(vector<int>& nums) {
        // goal: find the longest square subsequence
        // idea: 
        // we don't care the order of array 
        // use hashset, for each value, determine that if it is a start point
        // TC: O(n), SC: O(n)
        
        int ans = -1;
        unordered_set<long> st(nums.begin(), nums.end());
        for (long x: nums) {
            if (!isSq(x) || !st.count((int)sqrt(x))) { // we can start from this value
                int cur = 0;
                while (st.count(x)) {
                    cur++;
                    x = x*x;
                }
                if (cur > 1)
                    ans = max(ans, cur);
            }   
        }
        
        return ans;
    }
};
