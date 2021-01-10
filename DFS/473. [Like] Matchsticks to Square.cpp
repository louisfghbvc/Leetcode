// Nice pratice to do dfs.
// use set vis to fast speed.
class Solution {
public:
    int tar;
    vector<int> arr;
    int col[4];
    bool dfs(int i){
        if(i == arr.size()) return true;
        unordered_set<int> vis;
        for(int k = 0; k < 4; ++k){
            if(vis.count(col[k])) continue;
            if(col[k] + arr[i] <= tar){
                vis.insert(col[k]);
                col[k] += arr[i];
                if(dfs(i+1)) return true;
                col[k] -= arr[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot % 4) return false;
        tar = tot / 4;
        arr = nums;
        sort(arr.rbegin(), arr.rend());
        return dfs(0);
    }
};
