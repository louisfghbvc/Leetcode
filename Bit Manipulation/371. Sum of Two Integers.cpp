// Boring. ==
// so use shift and XOR and AND magic
class Solution {
public:
    
    int getSum(int a, int b) {
        unsigned int carry;
        while(b != 0){
            carry = (a&b);
            a = a^b;
            b = carry<<1;
        }
        return a;
    }
};
