// why bad need find parent, because it may be indirect.
// O(N*M log*), before connect, try to find this two root is in bad or not

class Solution {
public:
    vector<int> p;
    
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    
    bool Union(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        p[y] = x;
        return true;
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> res;
        p = vector<int>(n, -1);
        
        for(auto &v: requests){
            bool good = true;
            int x = find(v[0]), y = find(v[1]);
            
            for(auto &bad: restrictions){
                int bx = find(bad[0]), by = find(bad[1]);
                if((bx == x && by == y) || (by == x && bx == y)){ // same root
                    good = false;
                    break;
                }
            }
            
            if(good){
                Union(v[0], v[1]);
                res.push_back(true);
            }
            else res.push_back(false);
        }
    
        return res;
    }
};
