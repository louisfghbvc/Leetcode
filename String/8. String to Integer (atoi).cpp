// Nothing shit.
class Solution {
public:
    int myAtoi(string str) {
        int i;
        bool neg = 0;
        for(i = 0; i < str.size(); ++i){
            if(str[i] == ' ') continue;
            if(!isdigit(str[i]) && str[i] != '-' && str[i] != '+') return 0;
            else break;
        }
        if(i < str.size() && str[i] == '-') neg = 1;
        if(str[i] == '-' || str[i] == '+') i++;
        str = str.substr(i);
        long res = 0;
        for(char c: str){
            if(!isdigit(c)) break;
            res = res*10 + (c-'0');
            if(!neg && res > INT_MAX) return INT_MAX;
            else if(neg && -res < INT_MIN) return INT_MIN;
        }
        return neg ? -res : res;
    }
};
