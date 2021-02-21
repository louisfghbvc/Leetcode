// O(N). cuz number is small 
class Solution {
public:
    vector<vector<int>> g;
    vector<int> arr;
    vector<int> res;
    vector<int> dep;
    vector<int> mp[55];
    
    void dfs(int u, int f){
        for(int i = 1; i <= 50; ++i){
            if(mp[i].size() && __gcd(arr[u], i) == 1){
                int last = mp[i].back();
                if(res[u] == -1 || dep[u] - dep[last] < dep[u] - dep[res[u]]){
                    res[u] = last;
                }
            }
        }
        mp[arr[u]].push_back(u);
        for(int v: g[u]){
            if(v != f){
                dep[v] = dep[u]+1;
                dfs(v, u);
            }
        }
        mp[arr[u]].pop_back();
    }
    
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        arr = nums;
        
        g = vector<vector<int>>(n);
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        res = vector<int>(n, -1);
        dep = vector<int>(n);
        
        dfs(0, -1);
        
        return res;
    }
};

// Optimalize.
