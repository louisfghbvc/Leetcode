class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // goal: minimum time to repair all cars
        // idea: 
        // min: r * n
        // binary search the ans
        // x >= r * n^2
        // sqrt(x/r) >= n -> r*n^2 
        
        auto good = [&](long time) {
            long used = 0;
            for (int r: ranks) {
                long n = sqrtl(time/r);
                long cur = n * n * r;
                used += n;
                if (used >= cars) {
                    return true;
                }
            }    
            return false;
        };
        
        long l = 1, r = LLONG_MAX;
        long ans = 0;
        while (l <= r) {
            long mid = l + (r-l)/2;
            if (good(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        return ans;
    }
};
