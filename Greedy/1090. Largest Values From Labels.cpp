// O(NlogN). Sort. Problem statement confused me.

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        
        int n = values.size();
        int res = 0;
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; ++i){
            arr.push_back({values[i], labels[i]});
        }
        
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){ return a.first > b.first; } );
        
        unordered_map<int, int> mp;
        int cnt = 0;
        for(auto &[v, lab]: arr){
            if(cnt == num_wanted) break;
            if(mp[lab]++ >= use_limit) continue;
            res += v;
            cnt++;
        }
        
        return res;
    }
};
