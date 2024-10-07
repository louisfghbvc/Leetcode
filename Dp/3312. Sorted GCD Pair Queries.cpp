class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // goal: find the kth gcd pairs values
        // sort in ascending order
        // for each queries, need to find the kth gcd value
        
        // idea:
        // n = 3
        // [2,4,5]
        //  2, 1, 1
        
        // nums[i] <= 5 * 10^4
        // total number <= i - number of factors in i
        
        // i = 4
        // 2, 4
        // convert cnt[i]: 
        // using the sieve to find the number of divisors
        
        // (1, x), (2, y), (3, z), .... mx ()
        // => compute prefix
        // x, x+y
        // binary search to get the value

        // after looking the solution
        // we can use inclusion-exclusion principle to do that
        // cntGCD[2] = n*(n-1)/2 - cntGCD[4] - cntGCD[6] ...
        
        int mx = ranges::max(nums);
        
        vector<int> cnt(mx+1);
        for (int x: nums)
            cnt[x]++;

        vector<long> cntGCD(mx+1);
        for (int i = mx; i >= 1; --i) {
            long c = cnt[i]; // total number
            long val = 0;
            for (int j = 2*i; j <= mx; j += i) {
                c += cnt[j];
                val -= cntGCD[j]; // can't cover 2*i, 3*i, ...
            }
            val += c * (c-1)/2; // choose any two
            cntGCD[i] = val; 
        }

        // compute prefix sum
        for (int i = 1; i <= mx; ++i)
            cntGCD[i] += cntGCD[i-1];

        vector<int> res;
        for (auto q: queries) {
            res.push_back(
                lower_bound(cntGCD.begin(), cntGCD.end(), q+1) - cntGCD.begin());
        }

        return res;
    }
};
