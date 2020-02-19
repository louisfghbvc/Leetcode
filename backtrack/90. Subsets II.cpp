//4ms 9.4MB
class Solution {
public:
    void dfs(int st, vector<int>& nums, vector<int> &tmp, vector<vector<int>>&res, vector<bool> &vis){
        res.push_back(tmp);
        for(int i = st; i < nums.size(); ++i){
            if(vis[i]) continue;
            vis[i] = true;
            tmp.push_back(nums[i]);
            dfs(i + 1, nums, tmp, res, vis);
            tmp.pop_back();
            vis[i] = false;
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        vector<bool> vis(nums.size(), 0);
        vector<int> tmp;
        
        dfs(0, nums, tmp, res, vis);
        return res;
    }
};
