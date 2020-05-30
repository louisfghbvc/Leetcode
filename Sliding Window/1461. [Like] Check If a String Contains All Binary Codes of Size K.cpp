// Maintain window size with k. and hash
// O(N). 

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int d = 0;
        for(int r = 0, l = 0; r < s.size(); ++r){
            d = d*2 + s[r]-'0';
            if(r - l >= k-1){
                st.insert(d);
                d -= (s[l++]-'0') << (k-1);
            }
        }
        return st.size() == (1<<k);
    }
};
