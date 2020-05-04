// Just move to highest num and sub it
class Solution {
public:
    int findComplement(int num) {
        unsigned int i;
        for(i = 1; i <= num; i <<= 1);
        return i-1-num;
    }
};

// solution2 ~ <= complement a number
// same as solution1 but more trick.
// i default = 1111...1111 => 32bit
// if i and num then, shift
// finally ~ again and find 1's
class Solution {
public:
    int findComplement(int num) {
        unsigned i = ~0;
        while(i & num) i <<= 1;
        return ~i & ~num;
    }
};
