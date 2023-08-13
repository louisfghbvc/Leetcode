class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        // goal: calculate the minimum absolute difference
        
        // [4,3,2,4], x = 2
        //  [   ]
        //    [   ]
        
        // idea:
        // maintain a window size is x+1
        // add value into set
        // each search the set
        
        int n = nums.size();
        set<int> st;
        int ans = INT_MAX;
        for (int r = x, l = 0; r < n; ++r, ++l) {
            st.insert(nums[l]);
            auto it = st.upper_bound(nums[r]);
            if (it != st.end())
                ans = min(ans, *it - nums[r]);
            if (it != st.begin())
                ans = min(ans, nums[r] - *prev(it));
        }
        
        return ans;
    }
};
