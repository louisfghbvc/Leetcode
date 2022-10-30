class Solution {
public:
    
    // O(log10(n))
    int calDigit(long n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        // goal:
        // beatiful: sum of digit <= target
        // idea: add from lowest digit
        // time: O(log10(n) * log10(n))
        
        long ans = 0;
        long base = 10; // last digit
        while (calDigit(n) > target) { // not beautiful
            long x = (base - n % base); 
            ans += x;
            n += x;
            base *= 10;
        }
        return ans;
    }
};
