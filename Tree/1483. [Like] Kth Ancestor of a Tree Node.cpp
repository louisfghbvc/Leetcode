// Jump and Jump..
// Like fast pow. 5 => 101, cur node jump to 2^0 and jump to 2^2.
// build table O(N), get is O(1).

class TreeAncestor {
public:
    int p[5*10000+5][17];
    TreeAncestor(int n, vector<int>& parent) {
        for(int i = 0; i < n; ++i){
            p[i][0] = parent[i];
        }
        for(int k = 1; k < 17; ++k){
            for(int i = 0; i < n; ++i){
                if(p[i][k-1] != -1)
                    p[i][k] = p[p[i][k-1]][k-1];
                else p[i][k] = -1;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        // cout << (1<<16) << endl;
        int u = node;
        for(int i = 0; i < 17; ++i){
            if(k&(1<<i)){
                if(p[u][i] != -1)
                    u = p[u][i];
                else 
                    return -1;
            }
        }
        if(u != node) return u;
        return -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
