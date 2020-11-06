// O(NlogM).
// Easy to think that brute force is slow so binary search.

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int sum = 0;
            for(int x: nums) sum += (x+mid-1)/mid;
            if(sum <= threshold) r = mid - 1, ans = mid;
            else l = mid+1;
        }
        return ans;
    }
};
