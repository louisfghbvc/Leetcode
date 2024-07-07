class Solution {
public:
    string getEncryptedString(string s, int k) {
        // goal: right shift k times
        // idea:
        // 
        
        string res;
        for (int i = 0; i < s.size(); ++i) {
            res += s[(i+k)%s.size()];
        }
        return res;
    }
};
