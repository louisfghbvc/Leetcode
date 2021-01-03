// Dp lcs to lis.
// O(NlogN).

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> id;
        for(int i = 0; i < target.size(); ++i)
            id[target[i]] = i;
        
        vector<int> res;
        res.push_back(-1);
        for(int &x: arr){
            if(!id.count(x)) continue;
            
            int pos = id[x];
            if(pos > res.back()) res.push_back(pos);
            else *lower_bound(res.begin(), res.end(), pos) = pos;
            
            if((int)res.size()-1 == target.size()) return 0;
        }
        
        return target.size() - (res.size()-1);
    }
};
