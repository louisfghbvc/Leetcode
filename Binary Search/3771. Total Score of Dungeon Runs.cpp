class Solution {
public:
    long long totalScore(long hp, vector<int>& damage, vector<int>& requirement) {
        // goal: 
        // hp
        // n trap room
        // score(i) = number of points could get

        // idea:
        // brute force => TLE
        // [o o o] x => all subwindows survive
        // WA

        // for each index, we could know the number of contribute starting from j

        // prefix damage => increasing
        // starting from j, if i could pass?
        // hp - (pre[i]-pre[j-1]) >= requirement[i]
        // hp - pre[i] + pre[j-1] >= requirement[i]

        // pre[j-1] >= requirement[i] - hp + pre[i]
        // search [0,i] => how many pre[j-1] good

        int n = damage.size();
        vector<long> pre(n+1);
        for (int i = 1; i <= n; ++i)
            pre[i] += pre[i-1] + damage[i-1];

        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int j = lower_bound(pre.begin(), pre.begin()+i, requirement[i-1] - hp + pre[i]) - pre.begin();
            ans += i-j;
        }
        return ans;
    }
};
