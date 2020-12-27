// O(N). at most 1 zero. and start with 1, then append.
// otherwise. check zero numbers and append 1. zeroes always can push to continuious.
// hard to find pattern. QAQ

class Solution {
public:
    string maximumBinaryString(string s) {
        string res = "";
        int z = 0;
        for(auto&c: s) z += c == '0';
        for(auto&c: s){
            if(c == '1') res += c;
            else{
                for(int i = 0; i < z-1; ++i) res += '1';
                res += '0';
                break;
            }
        }
        while(res.size() < s.size()) res += "1";
        return res;
    }
};
