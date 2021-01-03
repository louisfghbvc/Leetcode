// Super Fast from back. dfs. 4ms.
// Prune + Space optimal.

class Solution {
public:
    int res = 0;
    int n;
    void dfs(int i, int vis = 0){
        if(i == 0){
            res++;
            return;
        }
        for(int j = n; j >= 1; --j){
            if(vis&(1<<j)) continue;
            if(i % j && j % i) continue;
            dfs(i-1, vis | (1<<j));
        }
    }
    int countArrangement(int n) {
        this->n = n;
        dfs(n);
        return res;    
    }
};
