//96ms 21.3MB
class Solution {
public:
    vector<int> g[10005];
    bool ok = true;
    void dfs(int u, vector<bool> &vis){
        vis[u] = true;
        for(int i = 0; i < g[u].size(); ++i){
            int t = g[u][i];
            if(!vis[t]){
                dfs(t, vis);
            }
            else
                ok = false;
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> vis(n, false);
        for(int i = 0; i < leftChild.size(); ++i){
            if(leftChild[i] >= 0)
                g[i].push_back(leftChild[i]);
        }
        for(int i = 0; i < rightChild.size(); ++i){
            if(rightChild[i] >= 0)
                g[i].push_back(rightChild[i]);
        }
        dfs(0, vis);
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                ok = false;
                break;
            }
        }
        return ok;
    }
};
