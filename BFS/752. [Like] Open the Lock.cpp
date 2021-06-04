// BFS. O(N).

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> dis(10000, 1e9);
        
        for(auto &s: deadends){
            dis[stoi(s)] = -1;
        }
        
        queue<pair<string, int>> q; 
        q.push({"0000", 0});
        
        while(q.size()){
            auto [s, cost] = q.front(); q.pop();
            if(cost > dis[stoi(s)]) continue;
            if(s == target) return cost;
            dis[stoi(s)] = cost;
            
            for(int i = 0; i < 4; ++i){
                char ord = s[i];
                for(int add : {1, 9}){
                    s[i] = '0' + ((s[i] - '0' + add) % 10);
                    if(dis[stoi(s)] > cost + 1){
                        dis[stoi(s)] = cost + 1;
                        q.push({s, cost+1});
                    }
                    s[i] = ord;
                }
            }
        }
        
        return -1;
    }
};

// Bidirectional BFS. more fast.
