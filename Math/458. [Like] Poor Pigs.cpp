// Poor math... QAQ
// think pig = 2. and test = 2. bucket = 9.
// 1 2 3
// 4 5 6
// 7 8 9.
// so two big can figure out poison pos
// so pig is dimension. can always find <= (test+1) ** pig.

class Solution {
public:
    int fpow(int a, int b){
        int res = 1;
        while(b){
            if(b&1) res *= a;
            a = a*a;
            b >>= 1;
        }
        return res;
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {        
        int test = minutesToTest / minutesToDie;
        int x = 0;
        while(fpow(test+1, x) < buckets) x++;
        return x;
    }
};
