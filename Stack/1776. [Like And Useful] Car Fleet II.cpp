// O(N). Math, Monotonous stack. 

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n);
        
        stack<int> st;
        // from backwards since pos is increasing. maintain a stack.
        // the major is stack top
        for(int i = n-1; i >= 0; --i){
            // check if i never catch stack top.
            while(st.size() && cars[st.top()][1] >= cars[i][1]) st.pop();
            double time = -1;
            while(st.size()){
                time = 1.0 * (cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
                if(res[st.top()] == -1 || time <= res[st.top()]) break;
                st.pop(); // can not catch
            }
            st.push(i);
            res[i] = time;
        }
        
        return res;
    }
};
