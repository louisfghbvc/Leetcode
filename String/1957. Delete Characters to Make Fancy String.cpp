class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for(char c: s){
            if(res.size() >= 2){
                int cn = res.size();
                if(res[cn-1] == res[cn-2] && res[cn-1] == c){
                    res.pop_back();
                }
            }
            res += c;
        }
        
        return res;
    }
};
