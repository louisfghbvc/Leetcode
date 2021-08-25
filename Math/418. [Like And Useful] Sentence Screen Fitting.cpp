// O(rows). jump ptrs, google problems
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s = "";
        for(auto &sen : sentence) s += sen + " ";
        int n = s.size();
        
        int ptr = 0;
        for(int r = 1; r <= rows; ++r){
            ptr += cols;
            if(s[ptr % n] == ' ') ptr++;
            else{ // when ptr is in the middle of word, move to previous word
                while(ptr > 0 && s[(ptr-1) % n] != ' ') ptr--;
            }
        }
        
        return ptr / n;
    }
};
