// 唬爛解 BFS. 
// add new option a-b. and just bfs. no sense.
// O(N).

class Solution {
public:
    unordered_set<int> gg;
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        bool vis[40005] = {};
        gg = unordered_set<int>(forbidden.begin(), forbidden.end());
        int res = -1;
        
        queue<tuple<int, bool, int>> q;
        q.push({0, 0, 0});
        int ab = a-b;
        while(q.size()){
            for(int s = q.size()-1; s >= 0; s--){
                auto [u, gob, c] = q.front(); q.pop();
                if(u > 20000) continue;
                if(vis[u]) continue;
                vis[u] = 1;
                if(u == x) return c;
                if(!gg.count(u+a)) q.push({u+a, 0, c+1});
                if(u - b > 0 && !gob && !gg.count(u-b)) q.push({u-b, 1, c+1});
                if(u+ab > 0 && !gg.count(u+ab) && !gg.count(u+a)) q.push({u+ab, 1, c+2});
            }
        }
        return -1;
    }
};

// Standard bfs. visited need 2D, make sure no ignore case.
// O(N).

class Solution {
public:
    unordered_set<int> gg;
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        bool vis[40005][2] = {};
        gg = unordered_set<int>(forbidden.begin(), forbidden.end());
        int res = -1;
        
        queue<pair<int, bool>> q;
        q.push({0, 0});
        int ans = 0;
        while(q.size()){
            for(int s = q.size()-1; s >= 0; s--){
                auto [u, gob] = q.front(); q.pop();
                if(u > 20000) continue;
                if(vis[u][gob]) continue;
                vis[u][gob] = 1;
                if(u == x) return ans;
                if(!gg.count(u+a)) q.push({u+a, 0});
                if(u - b > 0 && !gob && !gg.count(u-b)) q.push({u-b, 1});
            }
            ans++;
        }
        return -1;
    }
};
