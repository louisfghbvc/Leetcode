class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // goal: find the minimum xor num1
        // idea: 
        // first, find the bit count of num2
        
        int n2 = __builtin_popcount(num2);
        int n1 = __builtin_popcount(num1);
        
        if (n1 == n2) return num1;
        
        if (n1 > n2) {
            int dif = n1-n2;
            while (dif) {
                num1 = num1&(num1-1);
                dif--;
            }
            return num1;
        }
        
        int x = num1;
        int dif = n2-n1;
        for (int i = 0; i < 31 && dif; ++i) {
            if (x >> i & 1) continue;
            x |= 1<<i;
            dif--;
        }
        
        return x;
    }
};
