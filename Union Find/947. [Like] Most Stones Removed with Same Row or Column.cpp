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
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        p = vector<int>(2*n, -1);
        
        unordered_map<int, int> mpx;
        unordered_map<int, int> mpy;
        
        int group = 0;
        for(int i = 0; i < n; ++i){
            if(!mpx.count(stones[i][0])) group++, mpx[stones[i][0]] = mpx.size();
        }
        
        for(int i = 0; i < n; ++i){
            if(!mpy.count(stones[i][1])) group++, mpy[stones[i][1]] = mpx.size() + mpy.size();
        }
        
        for(int i = 0; i < n; ++i){
            if(uni(mpx[stones[i][0]], mpy[stones[i][1]])) group--;
        }
        
        return n - group;
    }
};


// find connected components
// O(N).
class Solution {
public:
    
    vector<int> p;
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(y == x) return;
        if(p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        p = vector<int>(n, -1);
        
        // union find to union connected components
        unordered_map<int, int> cols, rows;
        for(int i = 0; i < n; ++i){
            if(cols.count(stones[i][1])){
                uni(i, cols[stones[i][1]]);
            }
            else{
                cols[stones[i][1]] = i;
            }
            if(rows.count(stones[i][0])){
                uni(i, rows[stones[i][0]]);
            }
            else{
                rows[stones[i][0]] = i;
            }
        }
        
        // ans is sum of each componect group size - 1
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(p[i] < 0) res += abs(p[i]) - 1;
        }
        
        return res;
    }
};
