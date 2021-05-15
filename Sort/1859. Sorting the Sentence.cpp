class Solution {
public:
    string sortSentence(string s) {
        s += " ";
        map<int, string> mp;
        string tmp = "";
        for(char c: s){
            if(c == ' '){
                int val = tmp.back()-'0';
                tmp.pop_back();
                mp[val] = tmp;
                tmp = "";
            }
            else tmp += c;
        }
        string res = "";
        for(auto [k, v]: mp){
            res += v + " ";
        }
        res.pop_back();
        return res;
    }
};
