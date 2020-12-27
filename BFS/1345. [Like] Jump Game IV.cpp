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

// Bi-direction bfs. use set is slow.
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;
        
        vector<bool> vis(n);
        unordered_map<int, vector<int>> ind;
        for(int i = 0; i < n; ++i) ind[arr[i]].push_back(i);
        
        unordered_set<int> cur, other;
        cur.insert(0);
        other.insert(n-1);
        vis[0] = vis[n-1] = 1;
        
        int dist = 0;
        while(cur.size()){
            if(cur.size() > other.size()){
                swap(cur, other);
            }
            unordered_set<int> nxt;
            for(const int &u: cur){
                auto &id = ind[arr[u]]; 
                id.push_back(u+1);
                id.push_back(u-1);

                for(int &x: id){
                    if(other.count(x)) return dist+1;
                    if(x >= 0 && x < n && !vis[x]){
                        vis[x] = 1;
                        nxt.insert(x);
                    }
                }
                id.clear();
            }
            cur = nxt;
            dist++;
        }
        
        return dist;
    }
};
