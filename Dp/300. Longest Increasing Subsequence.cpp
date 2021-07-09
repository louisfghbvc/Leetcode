// Greedy add to small tail
// O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int x: nums){
            if(ans.empty() || x > ans.back()) ans.push_back(x);
            else *lower_bound(ans.begin(), ans.end(), x) = x;
        }
        return ans.size();
    }
};
