// definition of tree. n points, n-1 edges, no cycles.
// O(E).
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
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        p = vector<int>(n, -1);
        for(auto &e: edges){
            if(!uni(e[0], e[1])) return false;
        }
        return true;
    }
};
