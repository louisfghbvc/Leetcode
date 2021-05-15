class Solution {
public:
    
    bool isDec(const string &s){
        if(s.empty()) return false;
        int e = 0, dot = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '+' || s[i] == '-'){
                if(i != 0) return false;
            }
            if(s[i] == '.'){
                bool valid = i+1 < s.size() && isdigit(s[i+1]);
                valid += i>0 && isdigit(s[i-1]);
                if(!valid) return false;
            } 
            e += (s[i] == 'e' || s[i] == 'E');
            dot += s[i] == '.';
            if(isalpha(s[i]) && s[i] != 'e' && s[i] != 'E') return false;
        }
        return dot == 1 && e == 0;
    }
    
    bool isInt(const string &s){
        if(s.empty()) return false;
        int e = 0, dot = 0, d = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '+' || s[i] == '-'){
                if(i != 0) return false;
            }
            e += (s[i] == 'e' || s[i] == 'E');
            dot += s[i] == '.';
            d += isdigit(s[i]);
            if(isalpha(s[i]) && s[i] != 'e' && s[i] != 'E') return false;
        }
        return dot == 0 && e == 0 && d >= 1;
    }
    
    bool isNumber(string s) {
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'e' || s[i] == 'E'){
                return (isInt(string(s.begin(), s.begin()+i)) || isDec(string(s.begin(), s.begin()+i)))
                    && isInt(string(s.begin()+i+1, s.end()));
            }
        }
        return isInt(s) || isDec(s);
    }
};
