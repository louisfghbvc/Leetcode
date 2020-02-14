class Solution {
public:
    void dfs(int d, vector<int> tmp, vector<vector<int>> &res, vector<bool> &vis, vector<int>& nums){
	    if(d == nums.size()) return;
        res.push_back(tmp);
        for(int i = d; i < nums.size(); ++i){
            if(vis[i]) continue;
            vis[i] = true;
            tmp.push_back(nums[i]);
            dfs(i, tmp, res, vis, nums);
            tmp.pop_back();
            vis[i] = false;
        }
    }   
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> vis(nums.size(), 0);
        dfs(0, {}, ans, vis, nums);
        return ans;
    }
};
