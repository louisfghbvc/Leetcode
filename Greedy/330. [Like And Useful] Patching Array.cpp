// Very impressive !!!!
// so that's try from miss num = 1. entil n.
// if nums[i] is in the miss num range .add it so extend range.
// else add patch itself. miss.

// For example: input is nums = [1, 2, 4, 13, 43] and n = 100
// so from miss = 1.
// 124. => [0,8)
// when miss = 8, but num = 13 to big, can't make of 8. so add 8.
// now is become [0,16)
// and ya 13 can add it now become [0,29)
// and now 43 too big. can't become 29, so add 29
// [0,58) ya add 43
// [0,103) miss > n, end.

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0, i = 0;
        long miss = 1;
        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss){
                miss += nums[i++];
            }
            else{
                miss += miss;
                res++;
            }
        }
        return res;
    }
};
