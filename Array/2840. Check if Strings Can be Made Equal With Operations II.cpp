class Solution {
public:
    
    pair<string, string> convert(string &s) {
        string a, b;
        for (int i = 0; i < s.size(); ++i) {
            if (i & 1)
                a.push_back(s[i]);
            else
                b.push_back(s[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return {a, b};
    }
    
    bool checkStrings(string s1, string s2) {
        return convert(s1) == convert(s2);   
    }
};
