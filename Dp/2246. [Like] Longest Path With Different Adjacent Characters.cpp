class Solution {
public:
    
    // return the maximum length so far
    int dfs(int u) {
        
        vector<int> childs;
        for (int v: g[u]) {
            int child = dfs(v);
            if (s[v] != s[u]) {
                childs.push_back(child);
            }
        }
        
        sort(childs.rbegin(), childs.rend());
        childs.resize(min<int>(2, childs.size())); // only record 2
        
        if (childs.size() == 2) {
            ans = max(childs[0] + childs[1] + 1, ans);
        }
        else if (childs.size() == 1) {
            ans = max(childs[0] + 1, ans);
        }
        int ret = 1;
        if (childs.size()) ret += childs[0];
        return ret;
    }
    
    int longestPath(vector<int>& parent, string s) {
        // goal: find the longest path that adjacent chars is not the same
        // idea: postorder dfs
        // if child char, is not equal to root char
        // build the tree
        ans = 1;
        
        g.resize(s.size());
        for (int i = 1; i < s.size(); ++i) {
            g[parent[i]].push_back(i);
        }
        this->s = s;
        dfs(0);
        
        return ans;
    }
private:
    int ans;
    vector<vector<int>> g;
    string s;
};
