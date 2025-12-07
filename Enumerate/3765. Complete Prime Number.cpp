class Solution {
public:

    bool isPrime(long long x) {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        // find factor
        for (long long i = 3; i * i <= x; i += 2)
            if (x % i == 0) return false;
        return true;
    }
    
    bool completePrime(int num) {
        // goal: every prefix and suffix is prime
        
        // idea:
        // how?
        // 2,3,5,7 size 1
        // 293

        // try all possible
        // 20 check
        // 1 check sqrt(n)
        
        string s = to_string(num);
        int n = s.size();

        // check all prefixes
        for (int len = 1; len <= n; len++) {
            long long prefix = stoll(s.substr(0, len));
            if (!isPrime(prefix)) return false;
        }

        // check all suffixes
        for (int len = 1; len <= n; len++) {
            long long suffix = stoll(s.substr(n - len, len));
            if (!isPrime(suffix)) return false;
        }

        return true;
    }
};
