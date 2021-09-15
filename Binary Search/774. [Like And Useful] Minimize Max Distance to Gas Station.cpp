// O(NlogX). guess value. and give you the value, 
// you can easy to calculate the cost.

class Solution {
public:
    
    double minmaxGasDist(vector<int>& stations, int k) {
        int n = stations.size();
        
        auto check = [&](double except){
            int cost = 0;
            for(int i = 1; i < n; ++i){
                double diff = stations[i] - stations[i-1];
                if(diff > except){ // insert new points
                    cost += ceil(diff / except) - 1;
                }
            }  
            return cost <= k;
        };
        
        double l = 0.0, r = 1e8;
        double ans = 0.0;
        while(r - l >= 1e-6){
            double mid = (l+r)/2.0;
            if(check(mid)){
                ans = mid;
                r = mid;
            }
            else l = mid;
        }
        
        return ans;
    }
};
