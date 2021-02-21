// O(NMK) dp. actually no need to consider after first match fail
class Solution {
public:
    vector<vector<int>> g;
    vector<vector<vector<int>>> dp;
    bool dfs(int i, int j, int k, vector<int>& nums){
        if(i == g.size()) return true;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        bool res = false;
        if(k >= g[i].size()) 
            return dp[i][j][k] = dfs(i+1, j, 0, nums);
        if(j < nums.size() && g[i][k] == nums[j])
            res = dfs(i, j+1, k+1, nums);
        if(j < nums.size() && k == 0)
            res |= dfs(i, j+1, k, nums);
        return dp[i][j][k] = res;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int k = 0;
        for(auto &g: groups){
            k = max(k, (int)g.size());
        }
        g = groups;
        dp = vector<vector<vector<int>>> (groups.size(), vector<vector<int>>(nums.size()+2, vector<int>(k+2, -1)));
        return dfs(0, 0, 0, nums);
    }
};

// Greedy just check same, if all same move groupindex. --. simple
// can use kmp to faster compare.
// Greedy + Two Pointer
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, j = 0;
        while(i < groups.size() && j < nums.size()){
            int cnt = 0;
            while(j + cnt < nums.size() && cnt < groups[i].size() && groups[i][cnt] == nums[j + cnt]) cnt++;
            if(cnt == groups[i].size()){
                j += cnt;
                i++;
            }
            else{
                j++;
            }
        }
        return i == groups.size();
    }
};
