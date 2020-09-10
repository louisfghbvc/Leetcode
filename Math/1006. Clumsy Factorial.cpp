// O(N). Magic of math. when neg. just invert.

class Solution {
public:
    int clumsy(int N) {
        int c = 0, val = N;
        int res = 0;
        for(int i = N-1; i >= 1; --i){
            if(c == 0){
                val *= i;
            }
            else if(c == 1){
                val /= i;
            }
            else if(c == 2){
                val += i;
            }
            else{
                res += val;
                val = -i;
            }
            c++;
            c %= 4;
        }
        return res + val;
    }
};
