//20ms 11.8MB
class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' '){
                int j = i;
                for(; j < s.size() && s[j] != ' '; ++j);
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }

        return s;
    }
};
