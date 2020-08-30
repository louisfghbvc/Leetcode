// U want to find the length biggest, and positive subarray product. means, no zero and even count negtive numbers.
// so just record the first occur. and if encounter neg, p will change.
// so the ans will get. if p = neg, find the cur - (first neg), otherwise, find the cur - (first positive). 
// so that can be maximum, not dp pattern. like prefix 
// O(N)

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int p = 1, l = -1, nl = n;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0){
                p = 1;
                nl = n;
                l = i;
            }
            else{
                if(nums[i] < 0){
                    p = -p;
                    nl = min(nl, i);
                }
                if(p > 0) res = max(res, i-l);
                else res = max(res, i-nl);
            }
        }
        return res;
    }
};
