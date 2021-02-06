class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;
        int res = 0;
        for(auto [x, f]: mp) if(f == 1) res += x;
        return res;
    }
};
