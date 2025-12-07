class Solution {
public:
    int largestPrime(int n) {
        // goal: find the largest prime 

        // idea:
        // build the prime table
        // 2,3,5,7
        // enumerate from 2 => at least n

        vector<int> prime(n+1, 1);
        vector<int> num;
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                num.push_back(i);
                for (int j = 2*i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int sum = 0;
        int ans = 0;
        for (int x: num) {
            sum += x;
            if (sum > n) break;
            if (prime[sum]) {
                ans = sum;
            }
        }
        return ans;
    }
};
