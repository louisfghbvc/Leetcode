// O(N). Maintain window that has all unique numbers.

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int res = 0, sum = 0;
        for(int r = 0, l = 0; r < nums.size(); ++r){
            while(st.count(nums[r])){
                st.erase(nums[l]);
                sum -= nums[l++];
            }
            
            sum += nums[r];
            st.insert(nums[r]);
            
            res = max(sum, res);
        }
        return res;
    }
};
