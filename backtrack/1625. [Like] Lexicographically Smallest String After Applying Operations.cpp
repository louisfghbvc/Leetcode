// Enum all case, cuz this is small.
// use a set to check string is vis or not.
// O(10*N^2)

class Solution {
public:
    string res;
    unordered_set<string> st;
    int a, b;
    
    string rotate(string s, int b){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+b);
        reverse(s.begin()+b, s.end());
        return s;
    }
    
    string addA(string s, int a){
        for(int i = 1; i < s.size(); i += 2){
            int b = s[i]-'0';
            s[i] =  '0' + (b+a)%10;
        }
        return s;
    }
    
    void dfs(string s){
        if(st.count(s)) return;
        res = min(res, s);
        st.insert(s);
        dfs(addA(s, a));
        dfs(rotate(s, b));
    }
    
    string findLexSmallestString(string s, int a, int b) {
        res = s;
        this->a = a;
        this->b = b;
        dfs(s);
        return res;
    }
};
