// Monotonic Stack O(N).
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        stack<int> st;
        for(int i = heights.size()-1; i >= 0; --i){
            if(st.empty() || st.top() < heights[i]){
                res.push_back(i);
                st.push(heights[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// O(N). maintain stack
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        stack<int> st;
        for(int i = heights.size()-1; i >= 0; --i){
            while(!st.empty() && st.top() < heights[i]) st.pop();
            if(st.empty()) res.push_back(i);
            st.push(heights[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Solution1 Optimazation. record max
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int max_h = -1;
        for(int i = heights.size()-1; i >= 0; --i){
            if(heights[i] > max_h){
                max_h = heights[i];
                res.push_back(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
