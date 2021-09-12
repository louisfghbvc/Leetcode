// the idea is that only 1 from root ans not 1.
// other all 1. so we just jump. and only traversal once.
// O(N). Awesome

class Solution {
public:
    
    vector<vector<int>> g;
    vector<bool> vis;
    vector<int> num;
    
    void dfs(int u){
        if(!vis[num[u]]){
            vis[num[u]] = 1;
            for(int v: g[u]){
                dfs(v);
            }
        }
    }
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        g.resize(n);
        for(int i = 1; i < n; ++i)
            g[parents[i]].push_back(i);
        vis.resize(1e5+5);
        num = nums;
        
        vector<int> ans(n, 1);
        
        int miss = 1;
        int id = find(nums.begin(), nums.end(), 1) - nums.begin();
        while(id >= 0 && id < nums.size()){
            dfs(id);
            while(vis[miss]) miss += 1;
            ans[id] = miss;
            id = parents[id];
        }
        return ans;
    }
};
