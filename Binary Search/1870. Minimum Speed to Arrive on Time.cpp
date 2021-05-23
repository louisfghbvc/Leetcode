// Observe that. speed more, hour less, speed less, hour more.
// so if we search speed. more speed less hour use this.

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e8;
        int res = -1;
        int n = dist.size();
        while(l < r){
            int mid = (l+r) / 2;
            double tmp = 0;
            for(int i = 0; i < n; ++i){
                if(i == n-1) tmp += 1.0 * dist[i] / mid;
                else tmp += ceil(1.0 * dist[i] / mid);
            }
            if(tmp <= hour){ // speed to much
                res = mid;
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        
        return res;
    }
};
