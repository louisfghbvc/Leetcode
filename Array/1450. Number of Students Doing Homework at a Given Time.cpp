// A super easy problem.
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size(), cnt = 0;
        for(int i = 0; i < n; ++i){
            if(endTime[i] >= queryTime && queryTime >= startTime[i]) cnt++;
        }
        return cnt;
    }
};
