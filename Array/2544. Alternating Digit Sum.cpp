class Solution {
public:
    int alternateDigitSum(int n) {
        // goal: convert to bit
        // and reverse and add
        
        
        bool sign = true;
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        int ans = 0;
        for (int d: digits) {
            if (sign) ans += d;
            else ans -= d;
            sign = !sign;
        }
        return ans;
    }
};
