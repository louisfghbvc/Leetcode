class Solution {
public:
    string largestPalindromic(string num) {
        // goal: build the largest palindromic number
        // idea: convert number to frequency table
        // all even can use
        
        // build the smallest right value
        
        vector<int> fre(10);
        for (char d: num)
            fre[d-'0']++;
        
        string res;
        bool odd = false;
        char c = 0;
        for (int i = 0; i < 10; ++i) {
            if (fre[i] % 2) {
                odd = true;
                c = '0'+i;
            }
            res += string(fre[i]/2, '0'+i);
        }
        
        while (res.size() && res.back() == '0') res.pop_back();
        
        if (res.empty() && !odd) // all zero
            return "0";
        
        return string(res.rbegin(), res.rend()) + string(odd, c) + res;
    }
};
