// O(N). use stack.

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        
        // go through s.
        for(char c: s){
            // add c, empty or not equal
            if(st.empty() || st.back().first != c){
                st.push_back({c, 0});
            }
            if(++st.back().second == k) st.pop_back();
        }
        
        // do concat string.
        string res = "";
        for(auto &[c, f]: st)
            res.append(f, c);
        
        return res;
    }
};
