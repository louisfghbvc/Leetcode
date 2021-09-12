// Find and reverse.
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find(ch);
        reverse(word.begin(), word.begin()+i+1);
        return word;
    }
};
