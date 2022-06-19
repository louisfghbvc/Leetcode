// O(1)
class Solution {
public:
    int minimumNumbers(int num, int k) {
        // idea: math
        // num = n*k + 10(a1+....an), a any number
        // num % 10 = n*k % 10
        if (num == 0) return 0;
        for (int n = 1; n <= 10; ++n) {
            if (num >= n*k && (n*k) % 10 == num % 10)
                return n;
        }
        return -1;
    }
};

// O(N)
class Solution {
public:
    
    int solve(vector<int> &arr, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        
        for (int x: arr) {
            for (int w = x; w <= amount; ++w)
                dp[w] = min(dp[w], dp[w-x]+1);
        }
        
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
    
    int minimumNumbers(int num, int k) {
        // goal: find the minimum set, such that sum of number in the set is num
        // each number in the set, unit digit is k
        
        // dp, coin change
        vector<int> arr;
        for (int i = 0; i <= num; ++i)
            if (i % 10 == k)
                arr.push_back(i);
        
        return solve(arr, num);
    }
};
