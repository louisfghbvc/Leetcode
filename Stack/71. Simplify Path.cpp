// O(N). Boring problem...
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        path += '/';
        string tmp = "";
        for(char c: path){
            if(c == '/'){
                if(tmp.empty()) continue;
                if(tmp == ".."){
                    if(st.size()) st.pop_back();
                }
                else if(tmp != ".") st.push_back(tmp);
                tmp = "";
            }
            else tmp += c;
        }
        
        string res = "";
        for(auto &s: st) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};

// use getline to split. clean.
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string tmp;
        while(getline(ss, tmp, '/')){
            if (tmp == "" || tmp == ".") continue;
            if (tmp == ".." && st.size()) st.pop_back();
            else if (tmp != "..") st.push_back(tmp);
        }
        
        string res = "";
        for(auto &s: st){
            res += "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};
