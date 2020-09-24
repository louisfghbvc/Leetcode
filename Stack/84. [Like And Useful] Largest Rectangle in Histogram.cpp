// O(N). Stack, Monotonous.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        stack<int> st;
        int res = 0, i = 0, n = heights.size();
        while(i < n){
            if(st.empty() || heights[st.top()] < heights[i]) st.push(i++);
            else{
                int w = heights[st.top()]; st.pop();
                int len = st.empty() ? i : i-st.top()-1;
                res = max(res, w*len);
            }
        }
        return res;
    }
};

// Also can use segment tree.
