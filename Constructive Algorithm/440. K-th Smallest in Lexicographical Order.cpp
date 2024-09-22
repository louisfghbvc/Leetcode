class Solution {
public:
    int findKthNumber(int n, int k) {
        // goal: find the kth smallest integer range in [1, k]

        // idea:
        // think about the order
        //            1 
        //   10           11 ...
        // 100 101...  

        // when given a number, can we find out the order? wrong, int is not sort

        // after looking the solution

        // given a number we know the prefix of result
        // we know the values range
        // [res, res + 1]
        // [res * 10, (res + 1) * 10]
        // [res * 100, (res + 1) * 100]

        // we need to search level-by-level
        // when count is small => we need to search depth, too big


        long res = 1;
        for (--k; k; ) {
            int cnt = 0;
            for (long first = res, last = res+1; first <= n; first *= 10, last*= 10) 
                cnt += min<long>(last, n+1) - first;
            
            if (k >= cnt) { // skip to next digit
                res++;
                k -= cnt;
            }
            else { // too big, search depther in next level
                res *= 10;
                k--;
            }
        }


        return res;
    }
};
