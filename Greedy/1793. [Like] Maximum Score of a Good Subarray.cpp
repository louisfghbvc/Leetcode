// If u know trapping rain or something else. this is same as that.
// O(N). two pointer. from middle to bound

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k, r = k;
        int n = nums.size();
        int res = 0, cur = nums[k];
        while(l >= 0 && r < n){
            res = max(res, cur * (r-l+1));
            
            int left = 0;
            if(l > 0) left = nums[l-1];
            int right = 0;
            if(r+1 < n) right = nums[r+1];
            
            if(left < right){
                r++;
                cur = min(right, cur);
            }
            else{
                l--;
                cur = min(left, cur);
            }
            
        }
        return res;
    }
};
