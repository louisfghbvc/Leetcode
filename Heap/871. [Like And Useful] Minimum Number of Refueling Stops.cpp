// Knapsack O(N^2). Bottom up.

class Solution {
public:    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> dp(n+1); // dp[i]: use i stations can go maximum distance.
        dp[0] = startFuel; 
        
        for(int i = 0; i < n; ++i){
            for(int k = i; k >= 0; --k){ // optimize to from i. also can from n-1.
                if(dp[k] >= stations[i][0]){
                    dp[k+1] = max(dp[k+1], dp[k] + stations[i][1]);
                }
            }
        }
        
        for(int i = 0; i <= n; ++i){
            if(dp[i] >= target) return i;
        }
        
        return -1;
    }
};

// O(NlogN). Greedy. use largest refuel.
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        priority_queue<int> pq;
        
        int res = 0;
        for(int i = 0; startFuel < target; res++){
            while(i < stations.size() && startFuel >= stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            startFuel += pq.top(); pq.pop();
        }
        
        return res;
    }
};
