// Just like uva enter the dragon.
// the key idea is lowerbound find the no rain day after the rainy day
// pre is record previous day that are rain. Greedy Concept
// O(NlogN)

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = (int)rains.size();
        unordered_map<int, int> pre;
        vector<int> res(n, 1);
        
        set<int> norain;
        for(int i = 0; i < n; ++i){
            if(!rains[i]){
                norain.insert(i);
            }
            else{
                res[i] = -1;
                if(!pre.count(rains[i])){
                    pre[rains[i]] = i;
                }
                else{
                    // cout << rains[i] << endl;
                    auto p = norain.lower_bound(pre[rains[i]]);
                    if(p == norain.end()) return {};
                    res[*p] = rains[i];
                    norain.erase(p);
                    pre[rains[i]] = i;
                }
            }
        }
        
        return res;
    }
};
