class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        int ans = -1;
        for (int x: nums) {
            if (x > 0) {
                if (st.count(-x))
                    ans = max(ans, x);
            }
        }
        return ans;
    }
};
