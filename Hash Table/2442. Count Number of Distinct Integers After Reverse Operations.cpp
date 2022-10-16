class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        // goal: try to reverse the digit and count distinct
        // idea: use hashset to compute the distinct num
        
        unordered_set<int> st;
        
        for (int x: nums) {
            st.insert(x);
            string s = to_string(x);
            reverse(s.begin(), s.end());
            int y = stoi(s);
            st.insert(y);
        }
        
        return st.size();
    }
};
