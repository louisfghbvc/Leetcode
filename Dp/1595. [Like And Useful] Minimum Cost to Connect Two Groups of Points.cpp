// Well, maybe is classic, but not think out in contest.
// O(NM2^N).
// idea is not that hard, if u just not consider both, think about dp[i][mask], is until i boy minimum get. and mask is record the girl.
// so when i < boy. we just enum all girl who is smaller.
// when end, check the mask when girl not pair, it is possible if boy pair, girl not pair.
// Now, I understand. Bitmask is really useful with small state.
// Think small part, when 2 people, think about just 1 people can do

class Solution {
public:
    vector<vector<int>> cost;
    vector<int> min_girl;
    int boy, girl;
    int dp[13][(1<<12)+5];
    int dfs(int i, int mask){
        if(dp[i][mask] != -1) return dp[i][mask];
        int res = (i >= boy) ? 0 : INT_MAX;
        if(i >= boy){
            for(int j = 0; j < girl; ++j)
                if(!(mask&(1<<j)))
                    res += min_girl[j];
        }
        else{
            for(int j = 0; j < girl; ++j)
                res = min(res, cost[i][j] + dfs(i+1, mask|(1<<j)));
        }
        return dp[i][mask] = res;
    }

    int connectTwoGroups(vector<vector<int>>& cost) {
        this->cost = cost;
        boy = cost.size(), girl = cost[0].size();
        min_girl = vector<int>(girl, INT_MAX);
        
        for(int j = 0; j < girl; ++j)
            for(int i = 0; i < boy; ++i)
                min_girl[j] = min(min_girl[j], cost[i][j]);
        
        memset(dp, -1, sizeof dp);
        return dfs(0, 0);
    }
};
