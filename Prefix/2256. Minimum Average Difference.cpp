// just use prefix sum idea
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        // goal: min index of |pre[i]/(i+1) - (pre[n] - pre[i+1])/(n-i-1)|
        // idea: use total sum to do prefix and suffix 
        
        int n = nums.size();
        
        long sum = accumulate(nums.begin(), nums.end(), 0LL);
        
        int index = 0;
        long dis = numeric_limits<long>::max();
        int n1 = 0, n2 = n;
        long pre = 0;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            sum -= nums[i];
            n1++;
            n2--;
            long left = pre / (n1);
            long right = n2 == 0 ? 0 : sum / n2;
            long cur = abs(left - right);
            if (cur < dis) {
                dis = cur;
                index = i;
            }
        }
        
        return index;
    }
};
