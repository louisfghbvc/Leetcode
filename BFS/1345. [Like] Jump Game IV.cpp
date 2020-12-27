// So just push index to same value. O(N). and only go once.
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        vector<bool> vis(n);
        unordered_map<int, vector<int>> ind;
        for(int i = 0; i < n; ++i) ind[arr[i]].push_back(i);
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(q.size()){
            auto [u, cost] = q.front(); q.pop();
            if(u == n-1) return cost;
            if(vis[u]) continue;
            vis[u] = 1;
            if(u-1 >= 0 && !vis[u-1]) q.push({u-1, cost+1});
            if(u+1 < n && !vis[u+1]) q.push({u+1, cost+1});
            
            auto &id = ind[arr[u]]; 
            for(int i = id.size()-1; i >= 0; --i){
                int x = id.back();
                if(!vis[x]) q.push({x, cost+1});
                id.pop_back();
            }
        }
        
        return -1;
    }
};

// Bi-direction bfs. use vis as key and swap cur and other. O(N)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;
        
        vector<int> vis(n);
        unordered_map<int, vector<int>> ind;
        for(int i = 0; i < n; ++i) ind[arr[i]].push_back(i);
        
        queue<pair<int, int>> cur, other;
        cur.push({0, 1});
        other.push({n-1, 2});
        vis[0] = 1;
        vis[n-1] = 2;
        
        int dist = 0;
        while(cur.size()){
            if(cur.size() > other.size()){
                swap(cur, other);
            }
            for(int qs = cur.size()-1; qs >= 0; --qs){
                auto [u, key] = cur.front(); cur.pop();
                auto &id = ind[arr[u]]; 
                id.push_back(u+1);
                id.push_back(u-1);

                for(int &x: id){
                    if(x < 0 || x >= n) continue;
                    if(!vis[x]){
                        vis[x] = key;
                        cur.push({x, key});
                    }
                    else if(vis[x] != key) return dist+1;
                }
                id.clear();
            }
            dist++;
        }
        
        return dist;
    }
};
