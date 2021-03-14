// So each student add to most difference between origin.
// use heap to do that.
// O(MlogN)

class Solution {
public:
    typedef pair<int, int> ii;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, ii>> pq;
        
        for(auto &c: classes){
            pq.push({(double)(c[0]+1)/(c[1]+1) - (double)c[0]/c[1], {c[0], c[1]}});
        }
        while(extraStudents--){
            auto tp = pq.top(); pq.pop();
            tp.second.first++;
            tp.second.second++;
            tp.first = (double)(tp.second.first+1)/(tp.second.second+1) - (double)tp.second.first/tp.second.second;
            pq.push(tp);
        }
        
        double res = 0.0;
        while(pq.size()){
            res += (double)pq.top().second.first / pq.top().second.second; pq.pop();
        }
        
        return res / n;
    }
};
