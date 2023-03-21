class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        // goal: find the perm which is greater than nums as much as possible
        // idea: 
        // sort, and greedy
        sort(nums.begin(), nums.end());
        multiset<int> st(nums.begin(), nums.end());
        
        int ans = 0;
        for (int x: nums) {
            auto it = st.upper_bound(x);
            if (it == st.end()) break;
            ++ans;
            st.erase(it);
        }
        return ans;
    }
};
