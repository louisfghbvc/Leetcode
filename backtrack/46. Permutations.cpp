//8ms 9.2MB
class Solution {
public:
    void dfs(int st, vector<vector<int>> &ans, vector<int> &arr){
        if(st == arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i = st; i < arr.size(); ++i){
            swap(arr[st], arr[i]);
            dfs(st + 1, ans, arr);
            swap(arr[st], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(0, ans, nums);
        return ans;
    }
};
/**12ms 9.9MB
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
**/
