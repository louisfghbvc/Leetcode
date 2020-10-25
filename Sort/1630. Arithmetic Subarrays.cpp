// O(NNlogN).
// Simple partial sort. and check is Arithmetic or not.

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> res(m);
        vector<int> tmp;
        for(int i = 0; i < m; ++i){
            tmp = nums;
            sort(tmp.begin()+l[i], tmp.begin()+r[i]+1);
            bool ok = 1;
            for(int j = l[i]+1; j <= r[i]; ++j){
                ok &= (tmp[j] - tmp[j-1] == tmp[l[i]+1] - tmp[l[i]]);
            }
            res[i] = ok;
        }
        
        return res;
    }
};
