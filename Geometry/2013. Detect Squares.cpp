// Use map. at most count is O(T).

class DetectSquares {
public:
    map<pair<int, int>, int> mp;
    
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        
        for(auto &[it, f]: mp){
            if(it.second != y || it.first == x) continue;
            int diff = abs(it.first - x);
            
            if(mp.count({it.first, y + diff}) && mp.count({x, y + diff}))
                res += f * mp[{it.first, y + diff}] * mp[{x, y + diff}];
            
            if(mp.count({it.first, y - diff}) && mp.count({x, y - diff}))
                res += f * mp[{it.first, y - diff}] * mp[{x, y - diff}];
        } 
        
        return res;
    }
};

// use array. faster. careful calculate mp[i][y]. since duplicate.
// Count: O(1000)
class DetectSquares {
public:
    int mp[1005][1005];
    
    DetectSquares() {
        memset(mp, 0, sizeof mp);
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        
        // calculate in same y.
        for(int i = 0; i <= 1000; ++i) if(mp[i][y] > 0 && i != x){
            int dif = abs(i - x);
            if(y + dif <= 1000)
                res += mp[i][y] * mp[i][y + dif] * mp[x][y + dif]; 
            if(y - dif >= 0)
                res += mp[i][y] * mp[i][y - dif] * mp[x][y - dif];
        }
        
        return res;
    }
};
