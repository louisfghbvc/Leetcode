// BF. O(sqrt(N)).
class Solution {
public:
    int mySqrt(int x) {
        long i;
        for(i = 1; i*i <= x; ++i);
        return i-1;
    }
};

// O(1). binary lift.
class Solution {
public:
    int mySqrt(int x) {
        unsigned int res = 0;
        for(int i = 15; i >= 0; --i){
            unsigned int tmp = res+(1<<i);
            if(tmp*tmp <= x) res |= (1<<i);
        }
        return res;
    }
};
