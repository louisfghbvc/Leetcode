// BFS. MEMO. but can no use memo, level order.
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        const int N = 10000;
        auto valid = [&](int x){
            return x >= 0 && x <= N;    
        };
        if(!valid(start)) return -1;
        
        vector<int> dp(N+1, 1e9);
        queue<pair<int, int>> q;
        q.push({start, 0});
        dp[start] = 0;
        
        while(q.size()){
            auto [u, cost] = q.front(); q.pop();
            if(u == goal) return cost;
            if(dp[u] < cost) continue;
            
            for(int x: nums){
                if(valid(u - x) && dp[u-x] > cost+1){
                    dp[u-x] = cost+1;
                    q.push({u-x, cost+1});
                }
                if(u - x == goal) return cost+1;
                
                if(valid(u + x) && dp[u+x] > cost+1){
                    dp[u+x] = cost+1;
                    q.push({u+x, cost+1});
                }
                if(u + x == goal) return cost+1;
                
                if(valid(u ^ x) && dp[u^x] > cost+1){
                    dp[u^x] = cost+1;
                    q.push({u^x, cost+1});
                }
                if((u ^ x) == goal) return cost+1;
            }
        }
        
        return -1;
    }
};


// more clean.
class Solution {
public:
    
    bool valid(int x){
        return x >= 0 && x <= 1000;
    }
    
    int minimumOperations(vector<int>& nums, int start, int goal) {
        const int N = 1e4+5;
        queue<int> q;
        vector<bool> vis(N);
        
        q.push(start);
        int ops = 0;
        vis[start] = 1;
    
        while(q.size()){
            for(int qs = q.size()-1; qs >= 0; --qs){
                int u = q.front(); q.pop();
                if(u == goal) return ops;
                for(int x: nums){
                    for(int nxt: {u+x, u-x, u^x}){
                        if(valid(nxt) && !vis[nxt]){
                            vis[nxt] = 1;
                            q.push(nxt);
                        }
                        if(nxt == goal) return ops+1;
                    }
                }
            }
            ops++;
        }
        
        return -1;
    }
};
