// Loop twice, Cycle trick.
// O(N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> res(n, -1);
        vector<int> st;
        
        for(int i = 0; i < 2*n; ++i){
            // greater happened
            while(st.size() && nums[st.back()] < nums[i%n]){
                res[st.back()] = nums[i%n];
                st.pop_back();
            }
            st.push_back(i%n);
        }
        
        return res;
    }
};
