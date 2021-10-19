// O(N). use stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        stack<int> st;
        
        for(int i = nums2.size()-1; i >= 0; --i){
            while(st.size() && st.top() < nums2[i]) st.pop();
            if(st.size())
                mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        
        for(int i = 0; i < nums1.size(); ++i){
            if(mp.count(nums1[i])) res.push_back(mp[nums1[i]]);
            else res.push_back(-1);
        }
        
        return res;
    }
};
