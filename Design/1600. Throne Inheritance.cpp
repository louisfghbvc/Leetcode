// Boring. just tree traversal.
// and can also use string graph.

class ThroneInheritance {
public:
    unordered_map<int, string> name;
    unordered_map<string, int> id;
    unordered_set<string> dead; 
    
    unordered_map<int, vector<int>> g;
    
    ThroneInheritance(string kingName) {
        name[0] = kingName;
        id[kingName] = id.size();
    }
    
    void birth(string parentName, string childName) {
        if(!id.count(childName)){
            id[childName] = id.size();
            name[id[childName]] = childName;
        }
        g[id[parentName]].push_back(id[childName]);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void dfs(vector<string> &res, int u = 0){
        if(!dead.count(name[u])) res.push_back(name[u]);
        for(int v: g[u]){
            dfs(res, v);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(res);
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
