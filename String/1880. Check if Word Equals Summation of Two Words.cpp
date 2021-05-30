class Solution {
public:
    
    int to(string &s){
        int res = 0;
        for(char c: s)
            res = res * 10 + c - 'a';
        return res;
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return to(firstWord) + to(secondWord) == to(targetWord);
    }
};
