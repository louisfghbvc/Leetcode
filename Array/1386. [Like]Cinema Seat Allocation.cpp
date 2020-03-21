//600ms 87MB. Almost timelimit, but pass. use hash to speed up
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        int r = 1e4 + 5;
        vector<vector<bool>> vis(r, vector<bool>(11, 0));
        unordered_map<int, int> mp;
        for(int i = 0; i < reservedSeats.size(); ++i){
            if(!mp.count(reservedSeats[i][0])) mp[reservedSeats[i][0]] = mp.size();
            vis[mp[reservedSeats[i][0]]][reservedSeats[i][1]] = 1;
        }
        for(int i = 0; i < mp.size(); ++i){
            bool ok = false;
            if(!vis[i][2] && !vis[i][3] && !vis[i][4] && !vis[i][5]){
                ok = true;
                ans++;
            }
            if(!vis[i][6] && !vis[i][7] && !vis[i][8] && !vis[i][9]){
                ok = true;
                ans++;
            }
            if(!ok && !vis[i][4] && !vis[i][5] && !vis[i][6] && !vis[i][7]) ans++, ok = true;
            n--;
        }
        return n * 2 + ans;
    }
};
