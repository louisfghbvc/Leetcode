// O(N). Concise... dp
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, n);
        for(int i = 0; i < n; ++i){
            if(s[i] == c) res[i] = 0;
        }
        for(int i = 1; i < n; ++i){
            res[i] = min(res[i-1]+1, res[i]);
        }
        for(int i = n-2; i >= 0; --i){
            res[i] = min(res[i+1]+1, res[i]);
        }
        return res;
    }
};

// O(N). BFS.
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> res(n, n);
        
        vector<bool> vis(n);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(s[i] == c) q.push(i);
        }
        
        int dis = 0;
        while(q.size()){
            for(int S = q.size()-1; S >= 0; --S){
                int id = q.front(); q.pop();
                if(vis[id]) continue;
                vis[id] = 1;
                res[id] = dis;
                if(id > 0 && res[id-1] > dis){
                    q.push(id-1);
                } 
                if(id+1 < n && res[id+1] > dis){
                    q.push(id+1);
                } 
            }
            dis++;
        }
        
        return res;
    }
};
