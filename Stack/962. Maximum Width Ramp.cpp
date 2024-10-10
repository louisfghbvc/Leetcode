// DP with binary search

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // goal: find the maximum width where j-i is max, nums[i] <= nums[j]
        // idea:
        // TC: O(n^2)

        // n=3 
        // 1 2 3 => ans = 2
        // 

        // j>i, nums[j]<nums[i], i no use?
        // 1 2 3 2 ...        
        //     ^ ^
        // stack no

        // just use the set?
        // 3 2 3 2 1 1 4
        // ^.          ^  

        // 1. using binary index tree to find out the minimum index
        // 2. using dp
        // dp[i]: minimum index small than i

        // consider a a[i] => update dp
        // find the previous value of dp, closet to a[i]

        // 3 2 1 2 4
        // 0 1 2 x 0

        map<int, int> dp;
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto it = dp.upper_bound(nums[i]);
            if (it == dp.begin()) {
                dp[nums[i]] = i;
            }
            else {
                ans = max(ans, i - prev(it)->second);
                dp[nums[i]] = prev(it)->second;
            }
        }

        return ans;
    }
};

// Stack, Greedy
// The Stack value never use twice if we iterate reverse!

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // goal: find the maximum width where j-i is max, nums[i] <= nums[j]
        // idea:
        // TC: O(n^2)

        // n=3 
        // 1 2 3 => ans = 2
        // 

        // j>i, nums[j]<nums[i], i no use?
        // 1 2 3 2 ...        
        //     ^ ^
        // stack no

        // just use the set?
        // 3 2 3 2 1 1 4
        // ^.          ^  

        // 1. using binary index tree to find out the minimum index
        // 2. using dp
        // dp[i]: minimum index small than i

        // consider a a[i] => update dp
        // find the previous value of dp, closet to a[i]

        // 3 2 1 2 4
        // 0 1 2 x 0

        // idea2:
        // looking the solution we can use stack!
        // record monotonic sorted stack
        // decreased stack
        // 3 2 1   1 
        // now greedily from back since the value is largest!

        int n = nums.size();
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[i] < nums[st.back()])
                st.push_back(i);
        }

        int ans = 0;
        for (int i = n-1; i >= 0; --i) {
            while (st.size() && nums[i] >= nums[st.back()]) {
                ans = max(ans, i - st.back());
                st.pop_back();
            }
        }

        return ans;
    }
};
