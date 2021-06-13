class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i = left; i <= right; ++i){
            bool ok = 0;
            for(auto &v: ranges){
                if(i >= v[0] && i <= v[1]) ok = 1;
            }
            if(!ok) return false;
        }
        return true;
    }
};
