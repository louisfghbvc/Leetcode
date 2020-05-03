// O(N), Map the destination. check dest is in the map.
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        for(auto p : paths){
            mp[p[0]] = p[1];
        }
        for(auto x: mp){
            if(!mp.count(x.second)) return x.second;
        }
        return "";
    }
};
