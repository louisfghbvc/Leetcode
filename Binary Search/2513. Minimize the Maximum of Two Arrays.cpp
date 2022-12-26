class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        // goal: build the array, such that size is uniqueCnt, can't divisble by divisor
        // idea:
        // brute force
        // count from 1 -> TLE
        
        // guess a maximum number -> check uniqueCnt of each array
        // first: number divide the lcm -> get the total available cnts
        
        long lcm = (long)divisor1/__gcd(divisor1, divisor2)*divisor2;
        
        // divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2
        // lcm = 4
        // x = 13
        // a_get = x/4 - x/4 = 0
        // need = 8
        // b_get = 13 - 13/4 - 13/2 + 13/4 = 13 - 6 = 7
        // 4,8,12
        // 1,2,3,5,6,7,9,10,11,13
        
        // 2,4,6,8,10,12
        // 1,3,5,7,9,11,13,15 (b can get )
        
        auto good = [&](long x) {            
            // put b cannot get to a
            long a_get = x/divisor2 - x/lcm;
            
            if (a_get >= uniqueCnt1) { // enough
                long b_get = x-x/divisor2;
                return b_get >= uniqueCnt2;
            }
            else {
                long need = uniqueCnt1 - a_get;
                long b_get = x-x/divisor2-x/divisor1+x/lcm;
                if (b_get < need) return false;
                b_get -= need;
                return b_get+(x/divisor1-x/lcm) >= uniqueCnt2;
            }
            
            return true;
        };
        
        // binary search
        long l = 1, r = 1e14;
        long ans = 0;
        while (l <= r) {
            long mid = (l+r)/2;
            if (good(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        return ans;
    }
};
