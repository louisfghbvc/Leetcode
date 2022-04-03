// O(nlogx), space O(1)

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // goal: divide to k children candies
        // idea: binary search the ans
        
        long long sum = 0;
        for (int x: candies)
            sum += x;
        
        auto valid = [&](long x) {
            long cnt = 0;
            for (int val: candies)
                cnt += val / x;
            return cnt >= k;
        };
        
        long l = 1, r = sum / k;
        int ans = 0;
        while (l <= r) {
            long mid = (l + r) / 2;
            if (valid(mid)) l = mid+1, ans = mid;
            else r = mid-1;
        }
        
        return ans;
    }
};
