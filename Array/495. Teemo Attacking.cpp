// Really Simple, Just compare prev position. is cover or not
// O(N).
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res =  0;
        int pos = INT_MIN;
        for(int x: timeSeries){
            if(pos + duration < x) res += duration;
            else res += x - pos;
            pos = x;
        }
        return res;
    }
};
