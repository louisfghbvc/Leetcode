class Solution {
public:
    bool digitCount(string num) {
        
        for (int d = 0; d < num.size(); ++d) {
            char c = '0' + d;
            int cnt = count(num.begin(), num.end(), c);
            if (cnt != num[d] - '0') {
                return false;
            }
        }
        
        return true;
    }
};
