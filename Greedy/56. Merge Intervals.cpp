// O(NlogN). Just sort and compare last position. classic interval greedy problem.
// remember res back maybe bigger than origin.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        
        vector<vector<int>> res;
        int n = intervals.size();
        for(auto &x: intervals){
            if(res.empty() || x[0] > res.back()[1]) res.push_back(x);
            else{
                res.back()[1] = max(res.back()[1], x[1]);
            }
        }
        
        return res;
    }
};
