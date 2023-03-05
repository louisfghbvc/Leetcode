class Solution {
public:
    
    int findValidSplit(vector<int>& nums) {
        // goal: find the first product elements and last product elements gcd is 1
        // idea:
        // prime factors
        // TC: O(n * sqrt(x)) -> get each values primes
        // TC: O(n * p) -> check gcd
        
        vector<int> suffix(1e6+5, 0);
        for (int x: nums) {
            int o = x;
            for (int p = 2; p*p <= o; ++p) {
                if (x % p == 0) {
                    int cnt = 0;
                    while (x % p == 0) x/=p, cnt++;
                    suffix[p] += cnt; // suffix[2] += 3
                }
            }
            if (x != 1) suffix[x]++; // prime
        }
        
        unordered_map<int, int> prefix;
        for (int i = 0; i+1 < nums.size(); ++i) {
            int o = nums[i];
            int x = nums[i];
            for (int p = 2; p*p <= o; ++p) {
                if (x % p == 0) {
                    int cnt = 0;
                    while (x % p == 0) x/=p, cnt++;
                    prefix[p] += cnt;
                    suffix[p] -= cnt;
                }
            }
            if (x != 1) prefix[x]++, suffix[x]--; // prime
            
            // check if prefix == suffix
            bool ok = true;
            for (auto &[p, c]: prefix) {
                if (suffix[p]) { // gcd > 1
                    ok = false;
                    break;
                }
            }
            if (ok) return i;
        }
        
        return -1;
    }
};
