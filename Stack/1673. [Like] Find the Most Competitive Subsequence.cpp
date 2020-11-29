// O(N). Monotonous increase stack. 
// and maintain window size == k.
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int x = nums[i];
            int r = n-i-1;
            while((res.size()+r >= k || res.size() >= k) && res.size() && res.back() > x) res.pop_back();
            if(res.size() < k) res.push_back(x);   
        }
        return res;
    }
};
