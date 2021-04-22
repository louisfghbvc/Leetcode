// Idea is array tour. O(NlogN), N = RC

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> mp;
        
        int edge = 0;
        for(auto &r: wall){
            int x = 0;
            for(auto &c: r){
                mp[x+1]++;
                mp[x+c]--;
                x += c;
            }
            edge = max(edge, x);
        }
        
        int mn = wall.size();
        int sum = 0;
        for(auto &[x, f]: mp){
            if(x == edge) continue;
            sum += f;
            mn = min(sum, mn);
        }
        
        return mn;
    }
};

// Just use map, record maximum break edge.
// O(RC). 

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        
        int mx = 0;
        for(auto &r: wall){
            int x = 0;
            for(int j = 0; j+1 < r.size(); ++j){
                mp[x+r[j]]++;
                mx = max(mx, mp[x+r[j]]);
                x += r[j];
            }
        }
        
        return wall.size() - mx;
    }
};
