// Two lis. O(N^2).
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> l(n, 1), r(n, 1);
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]) l[i] = max(l[i], l[j]+1);
            }
        }
        for(int i = n-2; i >= 0; --i){
            for(int j = i+1; j < n; ++j){
                if(nums[i] > nums[j]) r[i] = max(r[i], r[j]+1);
            }
        }
        for(int i = 1; i+1 < n; ++i){
            res = max(res, l[i]+r[i]-1);
        }
        return n-res;
    }
};

// O(NlogN) lis + greedy binary search.
