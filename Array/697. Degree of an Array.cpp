// Clean O(N). one pass. map. just record first index.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), res = n;
        unordered_map<int, int> fre, L;
        int mx = 0;
        for(int i = 0; i < n; ++i){
            if(!L.count(nums[i])) L[nums[i]] = i;
            if(++fre[nums[i]] > mx){
                mx = fre[nums[i]];
                res = i - L[nums[i]] + 1;
            }
            else if(fre[nums[i]] == mx){
                res = min(res, i - L[nums[i]] + 1);
            }
        }
        
        return res;
    }
};

// Dirty pass. O(max number).
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int fre[50005] = {};
        vector<int> l(50005, n), r(50005);
        for(int i = 0; i < n; ++i){
            fre[nums[i]]++;
            l[nums[i]] = min(l[nums[i]], i);
            r[nums[i]] = max(r[nums[i]], i);
        }
        
        int mx = 0;
        for(int i = 0; i <= 50000; ++i) mx = max(fre[i], mx);
        
        int res = n;
        for(int i = 0; i <= 50000; ++i){
            if(fre[i] == mx) res = min(res, r[i]-l[i]+1);
        }
        
        return res;
    }
};
