// Just do backward, and monotonous stack.
// Many similiar problems.
// O(N)
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> res(n);
        stack<int> st;
        for(int i = n-1; i >= 0; --i){
            while(st.size() && heights[i] > heights[st.top()]){
                res[i]++;
                st.pop();
            }
            if(st.size())
                res[i]++;
            st.push(i);
        }
        
        return res;
    }
};
