// Just Spanning tree. O(N^2).

class Solution {
public:
    int p[1005];
    
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    struct node{
        int a, b, c;
        bool operator<(const node& n2){
            return c < n2.c;
        }
    };
    
    int dis(vector<int>& a, vector<int>& b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        vector<node> e;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                e.push_back({i, j, dis(points[i], points[j])});
            }
        }
        sort(e.begin(), e.end());
        
        memset(p, -1, sizeof p);
        
        for(int i = 0; i < e.size(); ++i){
            int a = find(e[i].a), b = find(e[i].b);
            if(a != b){
                res += e[i].c;
                p[b] = a;
            }
        }
        
        return res;
    }
};
