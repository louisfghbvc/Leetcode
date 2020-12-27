// Simulate by timestamp. Greedy pattern. if is in time push it.
// each time pop out pq until find apple. if find break.
// O(TlogN).

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = days.size();
        int i = 1;
        priority_queue<pair<int, int>> pq;
        
        int res = 0;
        for(int t = 1; t <= 50000; ++t){
            if(i <= t && i <= n){
                if(days[i-1]){
                    pq.push({-(i+days[i-1]), apples[i-1]});
                }
                i++;
            }
            
            while(pq.size()){
                auto [g, ap] = pq.top(); pq.pop();
                g = -g;
                if(t >= g) continue;
                res += ap > 0;
                ap--;
                if(ap){
                    pq.push({-g, ap});
                }
                break;
            }
        }
        
        return res;
    }
};
