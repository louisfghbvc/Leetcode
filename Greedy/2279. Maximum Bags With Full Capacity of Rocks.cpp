class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // goal: maximum the bags, where capacity[i] == rocks[i]
        // idea: calculate the difference
        // sort them from smallest
        
        vector<int> diff;
        for (int i = 0; i < rocks.size(); ++i)
            diff.push_back(capacity[i] - rocks[i]);
        
        sort(diff.begin(), diff.end());
        
        int res = 0;
        for (int i = 0; i < diff.size(); ++i) {
            if (additionalRocks >= diff[i]) {
                additionalRocks -= diff[i];
                res++;
            }   
            else break;
        }
        
        return res;
    }
};
