//0ms 6MB
//Not optimal. but easy to understand
class Solution {
public:
    int n = 45;
    int f[45];
    int findMinFibonacciNumbers(int k) {
        f[0] = 1, f[1] = 1;
        for(int i = 2; i < n; ++i){
            f[i] = f[i-1]+f[i-2];
        }
        int ans = 0;
        for(int i = 44; i >= 0; --i){
            while(f[i] <= k){
                k -= f[i];
                ans++;
            }
        }
        return ans;
    }
};
