// Digit dp, hard to think.
// f(n) is bitlen = n, number of not consective numbers.
// so f(n) = f(n-1)"0" + f(n-2)"01"
// From msb to lsb. 
// e.g 101100
// 1xxxxx add f(5)
// 101xxx add f(3)
// 1010xx add f(2)
// O(logN).

class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32);
        f[0] = 1, f[1] = 2;
        for(int i = 2; i < 31; ++i)
            f[i] += f[i-1] + f[i-2];
        
        int res = 0, prev_bit = 0;
        for(int i = 30; i >= 0; --i){
            if(n >> i & 1){ // bit is one
                res += f[i];
                if(prev_bit){ // consective one.
                    return res;
                }
                prev_bit = 1;
            }
            else{
                prev_bit = 0;
            }
        }
        
        return res + 1;
    }
};
