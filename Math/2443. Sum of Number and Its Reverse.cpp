class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        // goal: find the if the pair(a, reverse a) sum = num
        // idea: enumerate all possitive value
        
        // O(num*log10(num))
        for (int i = 0; i <= num; ++i) {
            int y = 0;
            int x = i;
            while (x) {
                y = y*10+x%10;
                x /= 10;
            }
            if (y + i == num)
                return true;
        }
        
        return false;
    }
};
