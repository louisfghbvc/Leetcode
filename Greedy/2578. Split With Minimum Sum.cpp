class Solution {
public:
    int splitNum(int num) {
        // goal: split the num to two nubmer
        // idea:
        // greedy, each digit is put the smallest number
        // 
        
        string s = to_string(num);
        sort(s.begin(), s.end());
        
        string a, b;
        bool odd = true;
        for (char c: s) {
            if (odd) a += c;
            else b += c;
            odd ^= 1;
        }
        return stoi(a) + stoi(b);
    }
};
