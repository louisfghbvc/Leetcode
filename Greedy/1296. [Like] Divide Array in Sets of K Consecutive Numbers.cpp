// O(NlogN)
// can do it O(N)
// build from small

class Solution {
public:
    
    // sort the array
    // and try to go through the array
    // check that each group has exactly k length
    
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k) return false;
        
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> mp;
        for(auto &x: nums) mp[x]++;
        
        for(int x: nums){
            if(mp[x] > 0){
                int base = x;
                for(int i = 0; i < k; ++i, base++){
                    if(mp[base] <= 0) return false;
                    mp[base]--;
                }
            }
        }
        
        return true;
    }
};
