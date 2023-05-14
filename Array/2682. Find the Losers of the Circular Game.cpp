class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        // goal: find the loser
        // idea: simulate it
        
        // TC: O(rounds + n)
        vector<int> cnt(n);
        int cur = 0;
        cnt[0]++;
        for (int i = 1; ; ++i) {
            cur = (cur + (i*k)) % n;
            cnt[cur]++;
            if (cnt[cur] > 1) break;
        }
        
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) ans.push_back(i+1);
        }
        return ans;
    }
};
