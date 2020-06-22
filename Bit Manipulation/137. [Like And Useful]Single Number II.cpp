// make every num as 32 bits. O(N)
// think about it 2 2 3 2, because every 3 times, so 1 bits must count %3 == 0
// 10
// 10
// 11
// 10
// 41 ==> %3 ==> 11
// Logical and easy understand.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; ++i){
            int sum = 0;
            for(auto &x: nums){
                sum += (x>>i) & 1;
            }
            res = res | ((sum%3) << i);
        }
        
        return res;
    }
};

// Tricky is this
// make bit state. 00->10->01->00
public int singleNumber(int[] A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.length; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}
