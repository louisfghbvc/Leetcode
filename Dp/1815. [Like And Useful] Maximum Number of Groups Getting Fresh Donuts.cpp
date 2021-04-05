// Dp + Greedy. So first enum
// use vector as key.

class Solution {
public:
    map<vector<int>, int> dp;
    int dfs(vector<int>&cnt, int left){
        auto it = dp.find(cnt);
        if (it != dp.end()) return it->second;
        int res = 0;
        for (int j = 1; j < cnt.size(); ++j) {
            if (cnt[j] == 0) continue;
            cnt[j] -= 1;
            res = max(res, (left == 0) + dfs(cnt, (cnt.size() - (j - left)) % cnt.size()));
            cnt[j] += 1;
        }
        return dp[cnt] = res;
    }
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> cnt(batchSize);
        int res = 0;
        for(auto &x: groups){ // enum 1, 2 group
            x %= batchSize;
            if(x == 0) res++;
            else if(cnt[batchSize - x]){
                res++;
                cnt[batchSize - x]--;
            }
            else{
                cnt[x]++;
            }
        }
        return res + dfs(cnt, 0);
    }
};
