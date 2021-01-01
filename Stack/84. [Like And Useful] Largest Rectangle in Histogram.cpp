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




// Solution3 use left and right array like kmp. just jump and jump from left and right.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = -1;
        right[n-1] = n;
        
        for(int i = 1; i < n; ++i){
            int p = i-1;
            while(p >= 0 && heights[p] >= heights[i]){
                p = left[p];
            }
            left[i] = p;
        }
        
        for(int i = n-2; i >= 0; --i){
            int p = i+1;
            while(p < n && heights[p] >= heights[i]){
                p = right[p];
            }
            right[i] = p;
        }
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        
        return res;
    }
};
