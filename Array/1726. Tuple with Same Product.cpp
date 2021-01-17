// O(N^2). like two sum prefix map.
// since all ele distinct.

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                res +=  mp[nums[i]*nums[j]];
                mp[nums[i]*nums[j]] += 8;
            }
        }
        return res;
    }
};
