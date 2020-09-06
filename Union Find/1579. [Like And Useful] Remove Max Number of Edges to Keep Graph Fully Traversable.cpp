// Two pass. Easy implement use two disjoint set. type 3 build 2 person graph.
// if type 1 or type 2, build that person. and cost if duplicate... Simple...
// OMG... almost solved in contest... QQ
// O(N). 

class Solution {
public:
    class DJ{
    public:
        vector<int> p;
        int edge;
        DJ(int n){
            p = vector<int>(n+1, -1);
            edge = 0;
        }
        int find(int x){
            return p[x] < 0 ? x : p[x] = find(p[x]);
        }
        int uni(int x, int y){
            x = find(x); y = find(y);
            if(x == y) return 1;
            p[y] = x;
            edge++;
            return 0;
        }
    };
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int res = 0;
        DJ Alice(n), Bob(n); 
        for(auto &e: edges){
            if(e[0] == 3){
                res += Alice.uni(e[1], e[2]);
                Bob.uni(e[1], e[2]);
            }  
        }
        for(auto &e: edges){
            if(e[0] == 1){
                res += Alice.uni(e[1], e[2]);
            }
            else if(e[0] == 2){
                res += Bob.uni(e[1], e[2]);
            }
        }
        if(Alice.edge != n-1 || Bob.edge != n-1) return -1;
        return res;
    }
};
