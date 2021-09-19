// BF. O(N^2)

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for(int i= 0; i <n; ++i){
            for(int j = i+1; j < n; ++j){
                res += abs(nums[i] - nums[j]) == k;
            }
        }
        return res;
    }
};


// prefix map, find 2 candidate. remove loop
// O(N).
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x: nums){
            res += mp[x+k] + mp[x-k];
            mp[x]++;
        }
        return res;
    }
};
