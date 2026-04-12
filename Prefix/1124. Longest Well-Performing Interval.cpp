class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // goal: find the longest subarray
        // such that tiring days > nontring

        // convert hours to bool
        // 1 -1 1
        // make tiring
        // pre[R] - pre[L-1] > 0 => means the range is good
        // pre[R] > pre[L-1]
        // pre[R] >= pre[L-1]+1
        // pre[L-1] <= pre[R]-1
        // in pre[L-1] smaller then R find the minimum i

        // just check pre[R]-1...

        unordered_map<int, int> mp;
        int n = hours.size();
        int pre = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            pre += hours[i] > 8 ? 1 : -1;
            if (pre > 0) {
                ans = i+1;
            }
            else {
                if (mp.count(pre - 1)) {
                    ans = max(ans, i - mp[pre - 1]);
                }
            }

            // update
            if (!mp.count(pre))
                mp[pre] = i;
        }
        return ans;
    }
};
