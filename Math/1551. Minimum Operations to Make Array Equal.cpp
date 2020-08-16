// Just Calculate mid. and add half.
// O(N).
class Solution {
public:
    int minOperations(int n) {
        int res = 0, mid;
        if(n % 2){
            mid = (n/2)*2+1;
        }
        else{
            mid = (((n/2)*2+1) + (((n-1)/2)*2+1))/2;
        }
        for(int i = 0; i < n/2; ++i){
            res += mid-(2*i+1);
        }
        return res;
    }
};
