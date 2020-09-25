// Simple sort. just compare 2 case. think greedy msb, lsb is fail.
// O(kNlogN)

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b){
            string ta = to_string(a), tb = to_string(b);
            return ta+tb > tb+ta ? true : false;
        });
        string res = "";
        for(int x: nums){
            if(res.empty() && x == 0) continue; 
            res += to_string(x);
        }
        return res.empty() ? "0" : res;
    }
};
