class Solution {
public:
    string removeDigit(string number, char digit) {
        // goal: remove one digit to make number largest
        // idea: do it reverse, from the right -> find first of occurence -> fail
        // 3213 -> remove 3
        // find the first increasing and number[i] == digit
        
        int n = number.size();
        int idx = number.find_last_of(digit);
        for (int i = 0; i+1 < n; ++i) {
            if (number[i] < number[i+1] && number[i] == digit) {
                idx = i;
                break;
            }
        }
        
        return number.substr(0, idx) + number.substr(idx+1);
    }
};
