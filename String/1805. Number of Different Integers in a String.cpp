// Careful bigint. O(N).

class Solution {
public:
    int numDifferentIntegers(string word) {
        word += 'a';
        string t = "";
        set<string> st;
        for(char c: word){
            if(isdigit(c)){
                if(t == "0") t = c;
                else t += c;
            }
            else{
                if(t.size()) st.insert(t);
                t = "";
            }
        }
        return st.size();
    }
};
