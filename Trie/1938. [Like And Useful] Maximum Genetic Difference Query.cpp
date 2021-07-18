// Build graph and offline process. use trie.
// O((N+M)logMX)

class Solution {
public:
    
    struct trie{
        trie* next[2] = {};
        int cnt = 0;
    };
    
    void add(trie* root, int x){
        trie* tmp = root;
        for(int i = 20; i >= 0; --i){
            bool b = x&(1<<i);
            if(!tmp->next[b]) tmp->next[b] = new trie();
            tmp = tmp->next[b];
            tmp->cnt++;
        }
    }
    
    void sub(trie* root, int x){
        trie* tmp = root;
        for(int i = 20; i >= 0; --i){
            bool b = x&(1<<i);
            tmp = tmp->next[b];
            tmp->cnt--;
        }
    }
    
    int search(trie* root, int x){
        trie* tmp = root;
        int mx = 0;
        for(int i = 20; i >= 0; --i){
            bool b = x&(1<<i);
            if(tmp->next[!b] && tmp->next[!b]->cnt){
                mx = mx | (1<<i);
                tmp = tmp->next[!b];
            }
            else{
                tmp = tmp->next[b];
            }
        }
        return mx;
    }
    
    vector<vector<int>> g;
    vector<vector<int>> todoList;
    vector<vector<int>> Q;
    vector<int> res;
    
    void dfs(trie* root, int u){
        add(root, u);
        for(int id: todoList[u]){
            res[id] = search(root, Q[id][1]);
        }
        for(int v: g[u]){
            dfs(root, v);
        }
        sub(root, u);
    }
    
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        trie* root = new trie();
        int n = parents.size();
        g = vector<vector<int>>(n);
        todoList = vector<vector<int>>(n);
        Q = queries;
        res = vector<int>(Q.size());
        
        int r;
        for(int i = 0; i < n; ++i){
            if(parents[i] != -1){
                g[parents[i]].push_back(i);
            }
            else{
                r = i;
            }
        }
        for(int i = 0; i < queries.size(); ++i){
            int u = queries[i][0];
            todoList[u].push_back(i);
        }
        
        dfs(root, r);
        
        return res;
    }
};
