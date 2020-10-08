// Array + Binary Search. 
// O(Nlog2). O(1).
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(!n) return false;
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i = 1; i < n; ++i){
            if(arr.back() < nums[i]) arr.push_back(nums[i]);
            else *lower_bound(arr.begin(), arr.end(), nums[i]) = nums[i];
            if(arr.size() >= 3) return true;
        }
        return false;
    }
};

// Simple solution. same idea  
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, big = INT_MAX;
        for(int x: nums){
            if(small >= x)
                small = x;
            else if(big >= x)
                big = x;
            else return true;
        }
        return false;
    }
};
