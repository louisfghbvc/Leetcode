// First we erase duplicate. and enum all start candidates.
// and just binary search the right bound.
// O(NlogN).

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            int end = nums[i] + n-1;
            int idx = upper_bound(nums.begin(), nums.end(), end) - nums.begin();
            res = max(res, idx - i);
        }
        return n - res;
    }
};


// Optimal solution O(NlogN) + Sliding window
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int res = 0;
        for(int i = 0, j = 0; i < nums.size(); ++i){
            int end = nums[i] + n-1;
            while(j < nums.size() && nums[j] <= end) j++;
            res = max(res, j - i);
        }
        return n - res;
    }
};
