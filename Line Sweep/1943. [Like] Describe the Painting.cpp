// Use this concept line sweep.
// O(NlogN). and just record the previous time.

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> res;
        map<int, long> mp;
        
        for(auto &seg: segments){
            mp[seg[0]] += seg[2];
            mp[seg[1]] -= seg[2];
        }
        
        int l = -1;
        long cur = 0;
        for(auto &[t, val]: mp){
            if(l != -1){
                if(cur != 0) 
                    res.push_back({l, t, cur});
            }
            l = t;
            cur += val;
        }
        
        return res;
    }
};
