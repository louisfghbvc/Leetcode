class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        // goal: find the maximum increasing array such that two subarray is strictly increase
        
        // idea:
        // visited number at most once
        // starting from each smallest number
        // two possible
        // 1. self half
        // 2. min(arr[i], arr[i+1])
        
        int n = nums.size();
        vector<int> arr;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n) {
                if (j != i) {
                    if (nums[j] <= nums[j-1]) break;
                }
                j++;
            }
            arr.push_back(j-i);
        }
        
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            ans = max(ans, arr[i]/2);
            if (i+1 < arr.size()) 
                ans = max(ans, min(arr[i], arr[i+1]));
        }
        return ans;
    }
};
