// Use stack. classic. but code dirty.
class Solution {
public:
    string gen(int r, string s){
        string t = "";
        for(int i = 0; i < r; ++i) t += s;
        return t;
    }
    string decodeString(string s) {
        int i = 0;
        stack<string> st;
        stack<int> ist;
        string ans = "";
        while(i < s.size()){
            if(i < s.size() && isdigit(s[i])){
                int t = 0;
                while(i < s.size() && isdigit(s[i])) t = t*10 + s[i++]-'0';
                ist.push(t);
            }
            else if(i < s.size() && isalpha(s[i])){
                string t = "";
                while(i < s.size() && isalpha(s[i])) t += s[i++];
                st.push(t);
            }
            else if(i < s.size() && s[i] == '[') st.push("["), i++;
            else if(i < s.size() && s[i] == ']'){
                string t = "";
                while(st.size() && st.top() != "["){
                    string add = st.top();
                    reverse(add.begin(), add.end());
                    t += add; st.pop();
                }
                if(st.size()) st.pop();
                reverse(t.begin(), t.end());
                int rep = ist.top(); ist.pop();
                t = gen(rep, t);
                st.push(t);
                i++;
            }
        }
        while(st.size()){
            string t = st.top();
            reverse(t.begin(), t.end());
            ans += t;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Clean version. awesome version
class Solution {
public:
    string gen(int r, string s){
        string t = "";
        for(int i = 0; i < r; ++i) t += s;
        return t;
    }
    string decodeString(string s) {
        stack<string> st;
        stack<int> ist;
        string ans = "";
        int k = 0;
        for(char c: s){
            if(isdigit(c)){
                k = k*10 + c-'0';
            }
            else if(c == '['){
                ist.push(k);
                st.push(ans);
                ans = "";
                k = 0;
            }
            else if(c == ']'){
                string tmp = ans; // after [ string
                ans = st.top(); st.pop(); // before [ string
                int num = ist.top(); ist.pop();
                ans += gen(num, tmp);
            }
            else{
                ans += c;
            }
        }
        return ans;
    }
};
