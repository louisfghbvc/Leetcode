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


// 0ms. prune
class Solution {
public:
    vector<bool> vis;
    bool dfs(vector<int> &arr, int tar, int i = 0, int cur = 0, int d = 0){
        if(d == 3) return true;
        if(cur == tar) return dfs(arr, tar, 0, 0, d+1);
        
        for(int j = i; j < arr.size(); ++j){
            if(cur + arr[j] <= tar){
                if(!vis[j]){
                    vis[j] = 1;
                    if(dfs(arr, tar, j + 1, cur + arr[j], d))
                        return true;
                    if(cur + arr[j] == tar) return false; // if equal length, impossible.
                    vis[j] = 0;
                }
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        
        // length must divisible by 4
        if(sum % 4) return false;
        sum /= 4;
        
        // largest one > length
        if(matchsticks[0] > sum) return false;
        
        vis = vector<bool>(matchsticks.size());
        
        return dfs(matchsticks, sum);
    }
};
