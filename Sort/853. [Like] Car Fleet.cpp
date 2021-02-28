// Math and Sort.
// O(NlogN). if time is bigger than current, means it can never catch the current fleet so new fleet.

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int cnt = 0;
        
        // sort from big to small
        // record the time to reach target.
        map<int, double> mp; 
        for(int i = 0; i < n; ++i){
            mp[-position[i]] = (double)(target - position[i]) / speed[i];
        }
        
        double current = -1;
        for(auto &[p, t]: mp){
            if(t > current){
                current = t;
                cnt++;
            }
        }
        
        return cnt;
    }
};
