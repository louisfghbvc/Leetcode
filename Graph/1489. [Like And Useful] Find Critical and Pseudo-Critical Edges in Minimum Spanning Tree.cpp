// O(E^2). Enumerate all case.
// this solution generate all spanning tree.
// mustUse make the sort not uniform. so that can catch all case
// and block means not use, that can find if is critical path. if not use that weight change. so this block edge, must critical.

class Solution {
public:
    int p[105], m;
    int findp(int x){
        return p[x] == -1 ? x : p[x] = findp(p[x]);
    }
    
    int mst(vector<vector<int>>& e, int block = -1, int mustUse = -1){
        memset(p, -1, sizeof p);
        int best = 0;
        
        if(mustUse != -1){
            int a = findp(e[mustUse][0]), b = findp(e[mustUse][1]);
            p[b] = a;
            best += e[mustUse][2];
        }
        
        for(int i = 0; i < m; ++i){
            if(i == block) continue;
            int a = findp(e[i][0]), b = findp(e[i][1]);
            if(a != b){
                p[b] = a;
                best += e[i][2];
            }
        }
        
        return best;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        m = edges.size();
        for(int i = 0; i < m; ++i){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](vector<int>&a, vector<int>&b){
            return a[2] < b[2];
        });
        
        int best = mst(edges);

        vector<int> retA, retB;
        for(int i = 0; i < m; ++i){
            if(best != mst(edges, i)){
                retA.push_back(edges[i][3]);
            }
            else if(best == mst(edges, -1, i)){
                retB.push_back(edges[i][3]);
            }
        }
        
        return {retA, retB};
    }
};
