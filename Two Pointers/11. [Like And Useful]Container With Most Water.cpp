// Very Tricky !!
// remove so many duplicate.
// Like greedy walk.
// O(N)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0, l = 0, r = n-1;
        while(l < r){
            res = max(res, min(height[l], height[r]) * (r-l));
            height[l] < height[r] ? l++ : r--;
        }
        return res;
    }
};
