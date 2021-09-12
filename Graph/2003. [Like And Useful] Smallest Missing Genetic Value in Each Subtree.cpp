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


// Union Find, Bottom up Dp. ans[u] >= ans[v].
class Solution {
public:
    
    vector<vector<int>> g; // graph
    vector<int> num; // genetic value
    vector<int> p; // union-find
    
    vector<int> ans;
    int n;
    
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        p[y] = x;
    }
    
    int dfs(int u){
        if(num[u] > n) num[u] = n+1;
        int res = 1;
        for(int v: g[u]){
            res = max(res, dfs(v));
            uni(num[u], num[v]);
        }
        while(res <= n && find(res) == find(num[u])) res++;
        return ans[u] = res;
    }
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        n = parents.size();
        p.resize(n+2, -1);
        
        g.resize(n);
        for(int i = 1; i < n; ++i)
            g[parents[i]].push_back(i);
        num = nums;
        ans = vector(n, 0);
        
        dfs(0);
        
        return ans;
    }
};
