// O(logN). use map.
// no need to -1. because not optimal. so use n/2 + n%2.
// means -1 until n%2 == 0, same as n%3.
// like greedy %2, %3 steps.
// QQ, not that hard. learn it!
class Solution {
public:
    unordered_map<int, int> dp;
    int minDays(int n) {
        if(n <= 1) return 1;
        if(dp.count(n)) return dp[n];
        int res = 1 + min(n%2 + minDays(n/2), n%3 + minDays(n/3));
        return dp[n] = res;
    }
};
