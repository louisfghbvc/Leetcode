// O(N). Very Simple, 3 step.
57. Insert Interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int nl = newInterval[0], nr = newInterval[1];
        int n = intervals.size(), i = 0;
        
        // smaller than new
        while(i < n && intervals[i][1] < nl) res.push_back(intervals[i++]);
        
        // merge
        while(i < n && intervals[i][1] >= nl && intervals[i][0] <= nr){
            nl = min(nl, intervals[i][0]);
            nr = max(nr, intervals[i][1]);
            i++;
        }
        res.push_back({nl, nr});
        
        // bigger than new
        while(i < n) res.push_back(intervals[i++]);
        
        return res;
    }
};
