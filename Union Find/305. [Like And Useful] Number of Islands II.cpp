// use map, and path compression
// O(P)

class Solution {
public:
    
    unordered_map<int, int> p;
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    bool uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        p[y] = x;
        return true;
    }
    
    // go through the positions, and try to a island, and try to merge all islands
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        
        int island = 0;
        for(auto &pt: positions){
            int x = pt[0], y = pt[1];
            if(!p.insert({x * n + y, -1}).second){
                res.push_back(island);
                continue;
            }
            island++;
            for(auto &[nx, ny] : vector<pair<int,int>>{{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}}){
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || !p.count(nx * n + ny)) continue;
                if(uni(x * n + y, nx * n + ny)) island--;
            }
            res.push_back(island);
        }
        
        return res;
    }
};

// use array, faster.
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
    
    // go through the positions, and try to a island, and try to merge all islands
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        p.assign(m * n, -1);
        vector<vector<bool>> vis(m, vector<bool>(n));
        
        int island = 0;
        for(auto &pt: positions){
            int x = pt[0], y = pt[1];
            if(vis[x][y]){
                res.push_back(island);
                continue;
            }
            vis[x][y] = 1;
            island++;
            for(auto &[nx, ny] : vector<pair<int,int>>{{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}}){
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || !vis[nx][ny]) continue;
                if(uni(x * n + y, nx * n + ny)) island--;
            }
            res.push_back(island);
        }
        
        return res;
    }
};
