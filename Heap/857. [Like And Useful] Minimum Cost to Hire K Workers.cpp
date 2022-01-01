// heap + O(NlogN)
// math
// tricky part is to figure out the cost = maximum quality * sum of k worker.

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>> arr;
        
        for(int i = 0; i < wage.size(); ++i)
            arr.push_back({1.0 * wage[i] / quality[i], 1.0 * quality[i]});
        
        sort(arr.begin(), arr.end());
        
        // (2.5, 20) (6.0, 5) (7.0, 10) 
        // 6.0 * 25
        
        double res = DBL_MAX;
        long sum_quality = 0;
        
        priority_queue<int> pq;
        for(auto &w: arr){
            sum_quality += w[1];
            pq.push(w[1]);
            if(pq.size() > k){
                sum_quality -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
                res = min(res, sum_quality * w[0]);
        }
        
        return res;
    }
};
