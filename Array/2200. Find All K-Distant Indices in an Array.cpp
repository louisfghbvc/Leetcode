// brute force can pass
// here is O(N) approach

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        // calculate the minimum distance to for each index i 
        
        int n = nums.size();
        vector<int> dis(n, k+1);
        int oc = -k-n;
        for(int i = 0; i < n; i++){
            if(nums[i] == key) oc = i;
            dis[i] = min(dis[i], i-oc);
        }
        oc = k+n;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] == key) oc = i;
            dis[i] = min(dis[i], oc-i);
        }
        
        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(dis[i] <= k)
                res.push_back(i);
        }
        return res;
    }
};
