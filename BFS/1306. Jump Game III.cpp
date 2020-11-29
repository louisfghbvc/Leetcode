// Simple Bfs O(N).
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<bool> vis(arr.size());
        while(q.size()){
            int u = q.front(); q.pop();
            if(!arr[u]) return true;
            vis[u] = 1;
            if(u + arr[u] < arr.size() && !vis[u + arr[u]]) q.push(u + arr[u]);
            if(u - arr[u] >= 0 && !vis[u - arr[u]]) q.push(u - arr[u]);
        }
        return false;
    }
};

// Space optimal not use visited array. just mark as neg. filp. or u can add a big value.
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        while(q.size()){
            int u = q.front(); q.pop();
            if(!arr[u]) return true;
            if(arr[u] < 0) continue;
            int l = u - arr[u], r = u + arr[u]; 
            arr[u] = -arr[u]; // tricky mark.
            if(l >= 0) q.push(l);
            if(r < arr.size()) q.push(r);
        }
        return false;
    }
};

// Recursive. dfs.
