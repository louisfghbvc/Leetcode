// ISMP.
// O(NlogN)
// sort by endtime
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int cnt = 0, x = INT_MIN;
        for(auto &v: intervals){
            if(v[0] >= x){
                x = v[1];
                cnt++;
            }
        }
        return intervals.size()-cnt;
    }
};
