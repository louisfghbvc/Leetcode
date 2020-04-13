//Very Trick. Hash all sum. if exist that sum, then get a ans.
//https://leetcode.com/problems/contiguous-array/Figures/535_Contiguous_Array.PNG
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int mx = 0, sum = 0;;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i] == 0 ? -1 : 1;
            if(!mp.count(sum)) mp[sum] = i;
            else{
                mx = max(i-mp[sum], mx);
            }
        }
        return mx;
    }
};
