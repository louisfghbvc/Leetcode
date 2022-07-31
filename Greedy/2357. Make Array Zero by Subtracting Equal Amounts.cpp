class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // goal: find the minimum operations such that convert all numbers to zero
        // idea: just return the number of distinct elements
        
        // time: O(N), space O(N)
        unordered_set<int> st(nums.begin(), nums.end());
        
        auto it = st.find(0);
        if (it != st.end())
            st.erase(it);
        
        return st.size();
    }
};
