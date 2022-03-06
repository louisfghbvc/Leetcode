// O(N).

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n = nums.size();
        
        unordered_map<int, int> mp; // target occurrence
        
        for(int i = 0; i+1 < n; ++i){
            if(nums[i] == key)
                mp[nums[i+1]]++;
        }
        
        int mx = 0, mx_num;
        for(auto &[target, fre]: mp){
            if(fre > mx){
                mx = fre;
                mx_num = target;
            }
        }
        
        return mx_num;
    }
};
