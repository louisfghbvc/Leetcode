// ugly code.
// O(N).

class Solution {
public:
    int calculate(string s) {
        deque<int> num;
        queue<char> as;

        stack<char> md;
        for(int i = 0; i < s.size(); i++){
            char c = s[i]; 
            if(c == '+' || c == '-' ) as.push(c);
            else if(c == '*' || c == '/') {
                md.push(c);
            }
            else if(isdigit(c)){
                long t = 0;
                while(i < s.size() && isdigit(s[i])) t = t*10+ s[i++]-'0';
                num.push_back(t), i--;
                
                bool add = false;
                if(md.size()) add = true;
                if(add){
                    char ct = md.top(); md.pop();
                    int b = num.back(); num.pop_back();
                    int a = num.back(); num.pop_back();

                    if(ct == '*') a = a*b;
                    else a = a/b;
                    num.push_back(a);
                }
                
            }
            
        }
        
        long res = 0;
        while(as.size()){
            char c = as.front(); as.pop();
            int a = num.front(); num.pop_front();
            int b = num.front(); num.pop_front();
            if(c == '+') a += b;
            else a -= b;
            num.push_front(a);
        }
        
        while(num.size()){
            res = num.front(); num.pop_front();
        }
        return res;
    }
};

// Clean and fast. O(n).
class Solution {
public:
    int calculate(string s) {
        s += '+';
        int res = 0, cur = 0;
        char sign = '+';
        long t = 0;
        for(char c: s){
            if(isdigit(c)) t = t*10 + c-'0';
            if(c == '+' || c == '-' || c == '*' || c == '/'){
                switch(sign){
                    case '+': cur += t; break;
                    case '-': cur -= t; break;
                    case '*': cur *= t; break;
                    case '/': cur /= t; break;
                }
                if(c == '+' || c == '-'){
                    res += cur;
                    cur = 0;
                }
                sign = c;
                t = 0;
            }
        }
        return res;
    }
};
