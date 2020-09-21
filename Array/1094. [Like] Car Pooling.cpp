// Think time stamp, so when start add, end out. check if a time stamp is over capacity.
// O(N)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int fre[1005] = {};
        for(auto & t: trips){
            fre[t[1]] += t[0];
            fre[t[2]] -= t[0];
        }
        
        int sum = 0;
        for(int i = 0; i <= 1000; ++i){
            sum += fre[i];
            if(sum > capacity) return false;
        }
        return true;
    }
};
