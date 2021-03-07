// Save ind value to Rank Tree.
// O(nqlogV + ElogV).

class Solution {
public:
    
    int N = 1e5+5;
    int bit[100005];
    
    void add(int x, int v){
        for(++x; x < N; x += x&-x)
            bit[x] += v;
    }
    
    int query(int x){
        int res = 0;
        for(++x; x; x -= x&-x)
            res += bit[x];
        return res;
    }
    
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> ind(n);
        
        vector<vector<int>> g(n);
        for(auto &e: edges){
            e[0]--, e[1]--;
            ind[e[0]]++;
            ind[e[1]]++;
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        int m = queries.size();
        vector<int> res(m);
        
        for(int i = 0; i < n; ++i){
            add(ind[i], 1);
        }
        
        for(int i = 0; i < n; ++i){
            add(ind[i], -1);
            for(int v: g[i]){
                if(v > i){
                    add(ind[v], -1);
                    ind[v]--;
                    add(ind[v], 1);
                }
            }
            for(int k = 0; k < m; ++k){
                if(ind[i] > queries[k]){
                    res[k] += n-1-i;
                }
                else{
                    int need = queries[k] - ind[i] + 1;
                    int suf = query(1e5+3) - query(need-1);
                    res[k] += suf;
                }
            }
            for(int v: g[i]){
                if(v > i){
                    add(ind[v], -1);
                    ind[v]++;
                    add(ind[v], 1);
                }
            }
        }
    
        return res;
    }
};
