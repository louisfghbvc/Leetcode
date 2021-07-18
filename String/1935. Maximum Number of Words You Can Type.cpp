// Simple O(N).

class Solution {
public:
    int canBeTypedWords(string text, string b) {
        text += " ";
        vector<bool> bad(26);
        for(char c: b) bad[c-'a'] = 1;
        
        int cnt = 0;
        string tmp = "";
        for(char c: text){
            if(c == ' '){
                bool ok = 1;
                for(char c: tmp) if(bad[c - 'a']) ok = 0;
                tmp = "";
                cnt += ok;
            }
            else tmp += c;
        }
        
        return cnt;
    }
};
