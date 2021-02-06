// maintain min and max. O(N).

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = 0, mn = 1e9;
        int sum = 0, sum2 = 0;
        for(int x: nums){
            sum += x;
            sum2 += x;
            if(sum < 0) sum = 0;
            if(sum2 > 0) sum2 = 0;
            mx = max(sum, mx);
            mn = min(sum2, mn);
        }
        return max(abs(mx), abs(mn));
    }
};
