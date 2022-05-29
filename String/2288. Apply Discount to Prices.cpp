class Solution {
public:
    
    string valid(string &s, int discount) {
        if (s[0] != '$') return s;
        if (s.size() == 1) return s;
        int dot = count(s.begin(), s.end(), '.');
        if (dot >= 2) return s;
        int dollar = count(s.begin(), s.end(), '$');
        if (dollar > 1) return s;
        
        for (char c: s) {
            if (isalpha(c)) return s; // may have letters
        }
        
        string t = s.substr(1);
        double val = stod(t);
        val *= 1.0 * (100 - discount) / 100.0;
        
        char buf[100] = {};
        sprintf(buf, "%0.2f", val);
        string sval = buf;
        
        return "$" + sval;
    }
    
    string discountPrices(string sentence, int discount) {
        // goal: change the sentence money to discount
        // idea: string parser
        // stringstream to split, check valid price
        
        stringstream ss(sentence);
        
        string res;
        while (ss >> sentence) {
            res += valid(sentence, discount);
            res += ' ';
        }
        
        res.pop_back(); // last space
        
        return res;
    }
};
