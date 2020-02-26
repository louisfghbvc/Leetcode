//8ms 10MB
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> st;
        for(auto &s: A){
            string s1 = "", s2 = "";
            for(int i = 0; i < s.size(); i ++){
                if(i & 1) s1 += s[i];
                else s2 += s[i];
            }
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            st.insert(s1 + s2);
        }
        return st.size();
    }
};
