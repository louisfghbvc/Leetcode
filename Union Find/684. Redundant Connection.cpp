class Solution {
public:
    vector<int> p;
    
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    
    bool uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        p[y] = x;
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p = vector<int>(n, -1);
        
        for(auto &e: edges){
            if(!uni(e[0]-1, e[1]-1)) return e;
        }
        
        return {};
    }
};
