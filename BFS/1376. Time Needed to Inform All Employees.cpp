//356ms 47.4MB, push all node, and get max num.
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& T) {
        vector<pair<int, int>> g[n + 1];
        for(int i = 0; i < m.size(); ++i){
            if(m[i] == -1) continue;
            g[m[i]].push_back({i, T[m[i]]});
        }
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({headID, 0});
        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();
            int u = p.first, now = p.second;
            ans = max(ans, now);
            for(int i = 0; i < g[u].size(); ++i){
                int v = g[u][i].first, c = g[u][i].second;
                q.push({v, now + c});
            }
        }
        
        return ans;
    }
};
