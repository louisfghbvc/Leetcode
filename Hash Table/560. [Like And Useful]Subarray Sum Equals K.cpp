// O(N), Space O(N)
// Very trick.
// key idea is prefix sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};
