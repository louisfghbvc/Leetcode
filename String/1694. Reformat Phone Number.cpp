// Dummy 3 case. check mod easy to check is remain
// O(N).
class Solution {
public:
    string reformatNumber(string number) {
        string s = "";
        for(char c: number) if(isdigit(c)) s+=c;
        
        int n = s.size();
        string res = "";
        if(n % 3 == 1){
            int i = 0;
            for(; i+4 < n; i+=3){
                res += s.substr(i, 3) + "-";
            }
            res += s.substr(i, 2) + "-" + s.substr(i+2, 2);
        }
        else if(n % 3 == 2){
            int i = 0;
            for(; i+3 < n; i+=3){
                res += s.substr(i, 3) + "-";
            }
            res += s.substr(i, 2);
        }
        else{
            int i = 0;
            for(; i < n; i+=3){
                res += s.substr(i, 3) + "-";
            }
            res.pop_back();
        }
        return res;
    }
};

// Recursive.
