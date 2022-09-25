class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        // goal: calculate the good index, such that the left is non-increasing
        // right is non-decreasing
        // idea: two pointers
        // first jump non-increasing then jump non-decreasing group
        // calculate the index in the group
        
        // idea2: two pass
        // first pass from left to right
        
        //.     
        // [2,1,1,1 | 3 | 4,1]
        //.     v v.  v
        
        // [2 | 1,1,1,3,4 | 1]
        //       v v v          
        
        int n = nums.size();
        
        vector<int> vis(n);
        
        vector<int> idx; // non-increasing sorted array index
        for (int i = 0; i < n; ++i) {
            if (idx.empty() || (idx.back()+1 == i && nums[idx.back()] >= nums[i])) {
                if (idx.size() >= k) {
                    vis[i]++;
                }
                idx.push_back(i);
            }
            else {
                if (idx.back()+1 == i) {
                    if (idx.size() >= k) 
                        vis[i]++;
                }
                idx.clear();
                idx.push_back(i);
            }
        }
        
        
        // from right to left
        reverse(nums.begin(), nums.end());
        idx.clear(); // non-increasing sorted array index
        for (int i = 0; i < n; ++i) {
            if (idx.empty() || (idx.back()+1 == i && nums[idx.back()] >= nums[i])) {
                if (idx.size() >= k) {
                    vis[n-1-i]++; 
                }
                idx.push_back(i);
            }
            else {
                if (idx.back()+1 == i) {
                    if (idx.size() >= k) 
                        vis[n-1-i]++;
                }
                idx.clear();
                idx.push_back(i);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (vis[i] == 2)
                ans.push_back(i);
        
        return ans;
    }
};
