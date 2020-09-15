// Boring Problem.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        while(s.size() && s.back() == ' ') s.pop_back();
        for(char c : s){
            if(c != ' ') len++;
            else len = 0;
        }
        return len;
    }
};
