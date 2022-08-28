class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // goal: calculate the minimum time that to collect all garbage
        // pick one unit take one minute
        // idea: three pass,
        // each pass collected the garbage
        
        // calculate one type of garbage
        auto cal = [&](char c) {
            int res = 0;
            int time = 0; // travel time
            
            int n = garbage.size();
            for (int i = 0; i < n; ++i) {
                string s = garbage[i];
                int cnt = count(s.begin(), s.end(), c); // how many garbage are there in this house?
                if (cnt) { // we only calculate time when we have garbage
                    res += time;
                    res += cnt;
                    time = 0; 
                }
                if (i != n-1) // we always has travel time
                    time += travel[i];
            }
            
            return res;
        };
        
        
        return cal('G') + cal('P') + cal('M');
    }
};
