//48ms 8.6MB. can use memo to speed up
class Solution {
public:
    int cntf(int x){
        if(x == 1) return 0;
        if(x % 2) x = 3*x + 1;
        else x = x/2;
        return 1 + cntf(x);
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;
        for(int i = lo; i <= hi; ++i){
             v.push_back({cntf(i), i});
        }
        sort(v.begin(), v.end());
        return v[k - 1].second;
    }
};
