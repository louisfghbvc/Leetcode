class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // goal: find the minimum group such that the interval can not intersect
        // idea: line sweep
        // compute the maximum interval overlapping count
        
        // maximum inteval -> s.size()
        
        
        map<int, int> cnt; // sorted
        
        for (auto &in : intervals) {
            cnt[in[0]]++;
            cnt[in[1]+1]--;
        }
        
        int flow = 0; // prefix
        int mx_flow = 0;
        for (auto &[time, f]: cnt) {
            flow += f;
            mx_flow = max(flow, mx_flow);
        }
        
        return mx_flow;
    }
};
