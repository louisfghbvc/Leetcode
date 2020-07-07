class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1]++;
        for(int i = n-1; i >= 1; --i){
            digits[i-1] += digits[i]/10; 
            digits[i] %= 10;
        }
        if(*digits.begin() >= 10){
            *digits.begin() = 0;
            digits.insert(digits.begin(), 1);
        } 
        return digits;
    }
};
