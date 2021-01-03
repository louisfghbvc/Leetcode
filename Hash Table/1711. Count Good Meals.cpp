// Just like two sum. and go through all pow of 2.
// O(22N).

class Solution {
public:
    const int mod = 1e9+7;
    int mp[1<<22];
    int countPairs(vector<int>& arr) {
        long res = 0;
        for(int &x: arr){
            for(int k = 0; k < 22; ++k){
                if(x > (1<<k)) continue;
                res += mp[(1<<k) - x];
                if(res >= mod) res -= mod;
            }
            mp[x]++;
        }
        return res;
    }
};
