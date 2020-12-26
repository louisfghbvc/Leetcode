// Just read problem, and keep previous time.
// O(N).

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double res = 0;
        int t = customers[0][0];
        for(auto &c: customers){
            t = max(t, c[0]);
            t += c[1];
            res += t - c[0];
        }
        
        return res / customers.size();
    }
};
