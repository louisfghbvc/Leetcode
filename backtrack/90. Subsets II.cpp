// Bakctracking, and compare prev and cur.

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    
    void dfs(vector<int> &arr, int i){
        res.push_back(tmp);
        for(int j = i; j < arr.size(); ++j){
            tmp.push_back(arr[j]);
            dfs(arr, j+1);
            tmp.pop_back();
            while(j + 1 < arr.size() && arr[j] == arr[j+1]) j++;
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};
