// O(N). Careful floating point issue.

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& arr) {
        long long res = 0;
        
        unordered_map<double, long> cnt;
        for(int i = 0; i < arr.size(); ++i){
            res += cnt[1.0 * arr[i][0] / arr[i][1]]++;
            
        }
        return res;
    }
};

// use gcd avoid floating point
