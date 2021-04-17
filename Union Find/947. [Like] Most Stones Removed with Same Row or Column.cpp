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
