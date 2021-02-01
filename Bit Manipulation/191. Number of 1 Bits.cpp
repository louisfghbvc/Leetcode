// bit trick, remove least significant bit.
// O(1).
// 11....10..0
// 11....01..1
// and => 11....00..0
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            cnt++;
            n &= n-1;
        }
        return cnt;
    }
};
