class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        
        int time = logs[0][1];
        int id = logs[0][0];
        
        int N = logs.size();
        for (int i = 1; i < N; ++i) {
            int cost = logs[i][1] - logs[i-1][1];
            if (cost > time) {
                time = cost;
                id = logs[i][0];
            }
            else if (cost == time)
                id = min(id, logs[i][0]);
        }
        
        return id;
    }
};
