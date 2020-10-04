// Sort left ascending, right descending. O(NlogN).
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int>&b){
            return a[0] < b[0] || (a[0]==b[0] && a[1] > b[1]);
        });
        int r = -1;
        for(auto &v: intervals){
            if(v[1] <= r) continue;
            else{
                cnt++;
                r = v[1];
            }
        }
        return cnt;
    }
};
