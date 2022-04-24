// neat code!
// O(NlogN)

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        // idea: divide start, end
        
        vector<int> enter, leave;
        for (auto &f: flowers)
            enter.push_back(f[0]), leave.push_back(f[1]);
        
        sort(enter.begin(), enter.end());
        sort(leave.begin(), leave.end());
        
        vector<int> res;
        for (auto &p: persons) {
            int num = upper_bound(enter.begin(), enter.end(), p) - enter.begin();
            // since equal is not leave
            int bad = lower_bound(leave.begin(), leave.end(), p) - leave.begin();
            res.push_back(num - bad);
        }
        
        return res;
    }
};

// line sweep, and binary search
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        // idea: line sweep
                 
        map<int, int> time;
        for (auto &f: flowers) {
            time[f[0]]++;
            time[f[1]+1]--;
        }
        
        map<int, int> vals; // time -> cnt
        int flow = 0;
        for (auto &[t, v] : time) {
            flow += v;
            vals[t] = flow;
        }
                     
        vector<int> res;
        for (auto &p: persons) {
            auto it = vals.upper_bound(p);
            if (it == vals.begin())
                res.push_back(0);
            else
                res.push_back(prev(it)->second);
        }
        
        return res;
    }
};

