// O(NlogN).
// just ignore y.

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> st;
        for(auto&p :points) st.insert(p[0]);
        int mx = 0;
        auto it = st.begin();
        for(auto i = next(it); i != st.end(); ++i){
            mx = max(mx, *i-*prev(i));
        }
        return mx;
    }
};
