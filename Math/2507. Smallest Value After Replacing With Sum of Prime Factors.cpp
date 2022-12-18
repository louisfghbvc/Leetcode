class Solution {
public:
    
    int prime_fac(int x) {
        int res = 0;
        int bound = sqrt(x);
        for (int p = 2; p <= bound; ++p) {
            while (x % p == 0)
                x /= p, res += p;
        }
        if (x != 1)
            res += x;
        return res;
    }
    
    int smallestValue(int n) {
        // goal: convert n to sum of its prime factors
        // idea:
        // try brute-force
        // TC: O(x * sqrt(n))
        
        while (1) {
            int next_value = prime_fac(n);
            if (next_value == n) break;
            n = next_value;
        }
        return n;
    }
};
