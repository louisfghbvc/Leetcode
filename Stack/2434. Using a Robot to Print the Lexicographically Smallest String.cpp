class Solution {
public:
    string robotWithString(string s) {
        // goal: build the lexigraphically smallest string
        // idea: simulate
        // build the array -> minChar[i]
        
        int n = s.size();
        vector<char> minChar(n);
        
        string res;
        string t;
        
        minChar.back() = s.back();
        for (int i = n-2; i >= 0; --i)
            minChar[i] = min(minChar[i+1], s[i]);
        
        for (int i = 0; i < n; ++i) {
            while (t.size() && t.back() <= minChar[i]) {
                res += t.back(); 
                t.pop_back();
            }
            t += s[i];
        }
        
        reverse(t.begin(), t.end());
        res += t;
        return res;
    }
};
