// Since small constraint. 
// and we just use array and parent to find ancestor, use dfs tree to find desc
// lock O(1), unlock O(1)
// upgrade O(N).

class LockingTree {
public:
    int n;
    vector<vector<int>> g;
    vector<int> p;
    vector<int> locked;
    
    LockingTree(vector<int>& parent) {
        n = parent.size();
        g.resize(n);
        p = parent;
        locked.resize(n);
        for(int i = 1; i < n; ++i){
            g[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(locked[num] != 0) return false;
        locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(locked[num] != user) return false;
        locked[num] = 0;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(locked[num] != 0) return false;
        if(!up(num)) return false;
        if(!down(num)) return false;
        locked[num] = user;
        return true;
    }
    
    bool up(int u){ // has lock in anc
        while(u != -1){
            if(locked[u] != 0) return false;
            u = p[u];
        }
        return true;
    }
    
    bool down(int u){
        bool res = false;
        for(int v: g[u]){
            if(locked[v] != 0) res = true;
            locked[v] = 0;
            res = res | down(v);
        }
        return res;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
