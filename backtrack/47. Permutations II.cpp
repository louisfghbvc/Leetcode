//24ms 9.9MB
class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int>& arr, int st, vector<bool> &vis, vector<int> &tmp){
        if(st == arr.size()){ 
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < arr.size(); ++i){
            if(vis[i]) continue;
            vis[i] = true;
            tmp.push_back(arr[i]);
            dfs(res, arr, st + 1, vis, tmp);
            tmp.pop_back();
            vis[i] = false;
            while(i < arr.size() - 1 && arr[i] == arr[i + 1]) i++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> vis(nums.size(), 0);
        sort(nums.begin(), nums.end());

        dfs(res, nums, 0, vis, tmp);
        
        return res;
    }
};
