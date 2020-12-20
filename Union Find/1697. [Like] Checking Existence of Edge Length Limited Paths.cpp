// Monotonous. just sort and union find.
// O(QlogQ + NlogN)

class Solution {
public:
    int p[100005];
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        p[y] = x;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& qy) {
        memset(p, -1, sizeof p);
        
        for(int i = 0; i < qy.size(); ++i){
            qy[i].push_back(i);
        }
        sort(e.begin(), e.end(), [&](vector<int> &a, vector<int> &b){
            return a[2] < b[2]; 
        });
        sort(qy.begin(), qy.end(), [&](vector<int> &a, vector<int> &b){
            return a[2] < b[2]; 
        });
        
        vector<bool> res(qy.size());
        int i = 0;
        for(auto &q: qy){
            int u = q[0], v = q[1], lim = q[2], id = q[3];
            for(; i < e.size(); ++i){
                if(e[i][2] >= lim) break;
                uni(e[i][0], e[i][1]);
            }
            res[id] = (find(u) == find(v));
        }
        
        return res;
    }
};
