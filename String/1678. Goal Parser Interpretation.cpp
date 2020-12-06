// O(N). BF.

class Solution {
public:
    string interpret(string s) {
        string res = "";
        int n = s.size();
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'G') res += "G";
            else if(i+1 < n && s[i] == '(' && s[i+1] == ')') res += "o";
            else if(i+3 < n && s[i] == '(' && s[i+1] == 'a' && s[i+2] == 'l' && s[i+3] == ')') res += "al";
        }
        
        return res;
    }
};
