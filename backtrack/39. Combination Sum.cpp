// 12ms 10.8MB
class Solution {
public:
    void dfs(int st, int &t, int v, vector<int> tmp, vector<vector<int>> &res, vector<int>& arr){
        if(v == t){
            res.push_back(tmp);
            return;
        }
        for(int i = st; i < arr.size() && v + arr[i] <= t; ++i){
            tmp.push_back(arr[i]);
            dfs(i, t, v + arr[i], tmp, res, arr);
            tmp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        dfs(0, target, 0, {}, res, candidates);
        
        return res;
    }
};
