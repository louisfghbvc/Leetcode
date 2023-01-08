class Solution {
public:
    typedef pair<int, int> ii;
    
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        // goal: find the time that all workers back to left
        // right side available go first, left side 
        
        // idea:
        // use maxheap for efficiency
        // need timestamp
        // min heap for leave warehouse
        
        priority_queue<ii> left_ok, right_ok; // {eff, i}
        priority_queue<ii, vector<ii>, greater<>> left_leave, right_leave; // {time, i}
        
        for (int i = 0; i < k; ++i) {
            left_ok.push({time[i][0]+time[i][2], i});
        }
        
        // 1. If the bridge is free, the worker waiting on the right side of the bridge gets to cross the bridge.
        // 2. If the bridge is free and no worker is waiting on the right side, and at least one box remains at the old
        //    warehouse, the worker on the left side of the river gets to cross the bridge. 
        
        // O(T + nlogn)
        int timestamp = 0;
        while (n > 0 || left_leave.size() + left_ok.size() != k) { 
            // do 1.right side
            while (right_leave.size() && right_leave.top().first <= timestamp) {
                auto [_, i] = right_leave.top(); right_leave.pop();
                right_ok.push({time[i][0]+time[i][2], i});
            }
            if (right_ok.size()) {
                auto [_, i] = right_ok.top(); right_ok.pop();
                timestamp += time[i][2]; // force walk briage
                // cout << "right to left " << timestamp << " " << i << '\n'; 
                left_leave.push({timestamp+time[i][3], i});
                continue;
            }
            
            // do 2. left size
            while (left_leave.size() && left_leave.top().first <= timestamp) {
                auto [_, i] = left_leave.top(); left_leave.pop();
                left_ok.push({time[i][0]+time[i][2], i});
            }
            if (n > 0 && left_ok.size()) { 
                auto [_, i] = left_ok.top(); left_ok.pop();
                timestamp += time[i][0];
                n--;
                // cout << "left to right " << timestamp << " " << i << '\n'; 
                right_leave.push({timestamp+time[i][1], i});
                continue;
            }
            
            timestamp++; // can improve
            // check left_leave, right_leave -> ok
        }
        
        return timestamp;
    }
};
