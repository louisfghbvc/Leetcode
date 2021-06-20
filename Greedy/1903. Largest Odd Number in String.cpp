// O(N). simple

class Solution {
public:
    string largestOddNumber(string num) {
        while(num.size() && (num.back() - '0') % 2 ==0) num.pop_back();
        return num;
    }
};
