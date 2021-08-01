// BF.

class Solution {
public:
    bool isThree(int n) {
        int res = 0;
        for(int i = 1; i <= n; ++i)
            res += n % i == 0;
        return res == 3;
    }
};
