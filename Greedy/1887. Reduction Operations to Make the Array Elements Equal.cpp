class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(auto &x: nums) mp[x]++;
        
        int res = 0;
        int dep = 0;
        for(auto &[k, v]: mp){
            res += dep * v;
            dep++;
        }
        return res;
    }
};
