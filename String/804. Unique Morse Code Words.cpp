//0ms 9MB
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(auto &s : words){
            string decode = "";
            for(int i = 0; i < s.size(); ++i){
                decode += code[s[i] - 'a'];
            }
            st.insert(decode);
        }

        return st.size();
    }
};
