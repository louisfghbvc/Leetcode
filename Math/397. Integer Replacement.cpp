// O(logN). number theory.
// but overflow issue
class Solution {
public:
    int integerReplacement(unsigned int n) {
        if(n == 1) return 0;
        if(n & 1) return 1+min(integerReplacement(n+1), integerReplacement(n-1));
        return 1 + integerReplacement(n/2);
    }
};

// odd/2. good avoid overflow.

class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(n & 1) return 2 + min(integerReplacement(n/2+1), integerReplacement(n/2));
        return 1 + integerReplacement(n/2);
    }
};
