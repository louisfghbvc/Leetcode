// Just Spanning tree. O(N^2log(N)).
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


// prim O(N^2), space: O(N)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        int total_weight = 0;
        int connected = 0, i = 0;
        vector<int> min_d(n, 1e9);
        
        while(++connected < n){
            min_d[i] = INT_MAX; // set selected
            int small_v = i;
            for(int j = 0; j < n; ++j){
                if(min_d[j] != INT_MAX){
                    min_d[j] = min(min_d[j], abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                    if(min_d[j] < min_d[small_v])
                        small_v = j;
                }
            }
            
            total_weight += min_d[small_v];
            i = small_v;
        }
        
        return total_weight;
    }
};
