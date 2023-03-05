class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1) return 1;
        if (n == 2) return 5;
        // 1+3+5 + 1+3+5 - 5
        long a = 1, b = 1+2*(n-1);
        return (a+b)*n-b;
    }
};
