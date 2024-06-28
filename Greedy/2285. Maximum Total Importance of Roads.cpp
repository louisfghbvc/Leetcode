class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // goal: given a graph, assign the value to the nodes, compute the maximum
        // idea:
        // just compute the node frequency, we can divide a edge to two nodes

        vector<int> cnt(n);
        for (auto& e: roads) {
            cnt[e[0]]++;
            cnt[e[1]]++;
        }

        sort(cnt.rbegin(), cnt.rend());
        
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long)cnt[i] * (n-i);
        }

        return ans;
    }
};
