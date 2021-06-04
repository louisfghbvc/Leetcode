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

// Bidirectional BFS. more fast. 8ms

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> v1(10000);
        vector<int> v2(10000);
        
        for(auto &s: deadends){
            v1[stoi(s)] = v2[stoi(s)] = -1;
        }
        
        int start = 0, end = stoi(target);
        if(v1[start] == -1) return -1;
        if(start == end) return 0;
        
        queue<int> q1, q2;
        q1.push(start);
        q2.push(end);
        v1[start] = v2[end] = 1;
        
        vector<int> base = {1, 10, 100, 1000};
        
        int s1 = 0, s2 = 0;
        while(q1.size() && q2.size()){
            s1++;
            
            int size = q1.size();
            for(int S = 0; S < size; ++S){
                int u = q1.front(); q1.pop();
                for(int i = 0; i < 4; ++i){
                    int d = (u / base[i]) % 10;
                    for(int nd: {(d + 1) % 10, (d + 9) % 10}){
                        int nxt = u - d * base[i] + nd * base[i];
                        if(v2[nxt] == 1) return s1 + s2;
                        if(v1[nxt]) continue;
                        q1.push(nxt);
                        v1[nxt] = 1;
                    }
                }
                
            }
            
            swap(q1, q2);
            swap(v1, v2);
            swap(s1, s2);
        }
        
        return -1;
    }
};
