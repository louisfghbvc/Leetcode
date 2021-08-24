// just implement.
class Solution {
public:
    pair<int, int> conv(string &s){
        // convert real part
        bool sign = 1; // 1 is positive
        int i = 0;
        if(s[i] == '-'){
            sign = 0;
            i++;
        }
        int val = 0;
        for(; s[i] != '+'; i++) 
            val = val * 10 + s[i] - '0';
        if(!sign) val = -val;
        
        // convert imagine part
        i++; sign = 1;
        if(s[i] == '-'){
            sign = 0;
            i++;
        }
        int val2 = 0;
        for(; i+1 < s.size(); i++) 
            val2 = val2 * 10 + s[i] - '0';
        if(!sign) val2 = -val2;
        return {val, val2};
    }
    string complexNumberMultiply(string num1, string num2) {
        auto A = conv(num1);
        auto B = conv(num2);
        // a, b, c, d => a*c - b*d + (a*d + b*c)i;
        
        return to_string(A.first * B.first - A.second * B.second)+ "+" + to_string(A.first * B.second + A.second * B.first) + "i";
    }
};

// super easy use sscanf, parser
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        return to_string(a1*a2-b1*b2) + "+" + to_string(a1*b2+b1*a2) + "i";
    }
};
