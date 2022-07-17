class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        // goal: ans[0]: pair number, ans[1]: remain
        // idea: map
        // TC: O(N), SC: O(N)
        
        unordered_set<int> st;
        vector<int> ans(2);
        for (int x: nums) {
            if (st.count(x)) {
                st.erase(x);
                ans[0]++;
            }
            else {
                st.insert(x);
            }
        }
        
        ans[1] = st.size();
        
        return ans;
    }
};
