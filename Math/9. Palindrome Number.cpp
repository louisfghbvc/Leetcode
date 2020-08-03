// Reverse half.
// Special is %10 or 0
// Finally if odd so revert/10, even is simple.
// ex: 12321
// O(log(X))
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int revert_num = 0;
        while(x > revert_num){
            revert_num = revert_num * 10 + x % 10;
            x /= 10;
        }
        return x == revert_num / 10 || x == revert_num;
    }
};
