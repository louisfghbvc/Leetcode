class Solution {
public:
    string removeStars(string s) {
        // idea: do from left to right
        // O(N)
        
        // when you encouter to star
        // erase the last element <- always be non star elements
        
        string res; // non star string
        for (char c: s) {
            if (c == '*') {
                if (res.size()) 
                    res.pop_back();
            }
            else res += c;
        }
        return res;
    }
};
