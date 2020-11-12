// 12ms. 9.2MB
// Main idea is avoid duplicate.
// so just after backtracking. check next number is same or not. to make sure head(or ...) is not duplicate.
// and just like origin permutation.
// vis can use int.
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &tmp, vector<int>&nums, vector<bool>& vis){
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(vis[i]) continue;
            vis[i] = 1;
            tmp.push_back(nums[i]);
            dfs(tmp, nums, vis);
            tmp.pop_back();
            vis[i] = 0;
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<bool> vis(nums.size());
        dfs(tmp, nums, vis);
        return res;
    }
};

// STL lib... omg don't know this is avoid duplicate.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return res;
    }
};
