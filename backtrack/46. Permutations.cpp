class Solution {
public:
    void dfs(int d, vector<int> v, vector<vector<int>> &ans, vector<bool> &vis, vector<int> &arr){
        if(v.size() == arr.size()){
            ans.push_back(v);
            return;
        }
        for(int i = 0; i < arr.size(); ++i){
            if(vis[i]) continue;
            vis[i] = 1;
            v.push_back(arr[i]);
            dfs(d+1, v, ans, vis, arr);
            v.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(), 0);
        vector<vector<int>> ans;
        dfs(0, {}, ans, vis, nums);
        return ans;
    }
};
