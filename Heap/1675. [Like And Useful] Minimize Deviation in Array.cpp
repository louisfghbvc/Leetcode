// use set to maintain heap.
// so observe that. odd can*2 once. so odd we just*2. so that odd never *2 again.
// only down biggest.
// and when biggest is even. can down to biggest/2.
// O(NlogNlogK). use tree.

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        for(int x: nums){
            st.insert(x % 2 ? x*2 : x);
        }
        int res = *st.rbegin() - *st.begin();
        while(*st.rbegin() % 2 == 0){
            st.insert(*st.rbegin() / 2);
            st.erase(*st.rbegin());
            res = min(res, *st.rbegin() - *st.begin());
        }
        return res;
    }
};
