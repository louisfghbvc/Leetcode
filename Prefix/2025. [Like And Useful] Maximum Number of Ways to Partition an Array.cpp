// O(N), impressive, math
// enumerate all index. record suf - pre map
// and u just find right part that can use cur get that. and left part is just inverse.

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        // choose i prefix = suffix
        
        int n = nums.size();
        long suf = accumulate(nums.begin(), nums.end(), 0L);
        
        unordered_map<long, int> right, left; // record difference map
        vector<int> dif;
        
        // origin, pivot
        int res = 0;
        
        long pre = 0;
        for(int i = 0; i+1 < n; ++i){
            pre += nums[i]; 
            suf -= nums[i]; 
            
            res += pre == suf;
            
            right[suf-pre]++;
            dif.push_back(suf-pre);
        }
        
        // enumerate all index, change i
        for(int i = 0; i < n; ++i){
            int val = k - nums[i];
            int cur = 0;
            
            // right part can change prefix
            if(right.count(val)) cur += right[val];
            
            // left part can change suffix, math(suffix add value means prefix sub value)
            if(left.count(-val)) cur += left[-val];

            res = max(res, cur);
            if(i+1 < n){
                right[dif[i]]--;
                left[dif[i]]++;
            }
        }
        
        return res;
    }
};
