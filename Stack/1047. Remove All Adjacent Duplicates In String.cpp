// Easy stack concept. O(N)

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for(char c: s){
            if(res.empty() || res.back() != c) res += c;
            else res.pop_back();
        }
        return res;
    }
};
