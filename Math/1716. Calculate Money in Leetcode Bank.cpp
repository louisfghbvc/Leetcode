class Solution {
public:
    int totalMoney(int n) {
        int c0 = 1, c1 = 1;
        int res = 0;
        for(int i = 1; i <= n; ++i){
            res += c1;
            if(i % 7 == 0){
                c1 = c0++;
            }
            c1++;
        }
        return res;
    }
};
