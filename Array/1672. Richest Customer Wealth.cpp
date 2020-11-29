// Too simple. O(N^2).

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(auto &r: accounts){
            int tmp = accumulate(r.begin(), r.end(), 0);
            res = max(tmp, res);
        }
        return res;
    }
};
