// m == 10. n == 50. backtracking.
// O(?) exponential time.
class Solution {
public:
    vector<int> arr;
    vector<int> qt;
    bool dfs(int i){
        if(i >= qt.size()) return true;
        for(int j = 0; j < arr.size(); ++j){
            if(arr[j] >= qt[i]){
                arr[j] -= qt[i];
                if(dfs(i+1)) return true;
                arr[j] += qt[i];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for(auto &x: nums) mp[x]++;
        for(auto &[a, b]: mp) arr.push_back(b);
        sort(arr.rbegin(), arr.rend());
        qt = quantity;
        sort(qt.rbegin(), qt.rend());
        return dfs(0);
    }
};

// Dp. Top down. slow. O(n4^m?)
class Solution {
public:
    vector<int> arr;
    vector<int> qt;
    int dp[55][1024];
    int n, m;
    bool dfs(int i, int mask){
        if(mask == (1<<m)-1) return 1;
        if(i == n) return 0;
        if(dp[i][mask] != -1) return dp[i][mask];
        
        bool res = dfs(i+1, mask);
        for(int j = 0; j < (1<<m); ++j){
            if(mask != (mask&j)) continue;
            int n_mask = mask;
            int sum = 0;
            for(int k = 0; k < m; ++k){
                if(mask&(1<<k)) continue;
                if(j&(1<<k)){
                    sum += qt[k];
                    n_mask |= (1<<k);
                }
            }
            if(sum <= arr[i])
                res |= dfs(i+1, n_mask);
        }
        
        return dp[i][mask] = res;
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for(auto &x: nums) mp[x]++;
        for(auto &[a, b]: mp) arr.push_back(b);
        qt = quantity;
        
        memset(dp, -1, sizeof dp);
        n = arr.size();
        m = qt.size();
        
        return dfs(0, 0);
    }
};

// Bottom - up clear and maybe easy to understand.
// O(n3^m). dp can choose i or not choose i.
// n = arr.size, m = quantity.size()
// base is dp[n][(1<<m)-1] = 1
// so dp[i][j] = dp[i+1][j]. if not choose i. j just from next mask.
// and choose i need to consider all (Not mask) of submask.
// means j = 1 can not use. use 0. think j = 10101. so submask is from 01010.
// if ok[i][submask]. means submask is small than arr[i] don't consider i+1 sum. just consider current sum.
// so can choose. dp[i][j] = dp[i+1][j|submask].

class Solution {
public:
    vector<int> arr;
    bool dp[55][1<<10];
    bool ok[55][1<<10];
    int n, m;
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        memset(dp, 0, sizeof dp);
        memset(ok, 0, sizeof ok);
        unordered_map<int, int> mp;
        for(auto &x: nums) mp[x]++;
        for(auto &[a, b]: mp) arr.push_back(b);

        n = arr.size();
        m = quantity.size();
        dp[n][(1<<m)-1] = 1;
        
        for(int i = n-1; i >= 0; --i){
            for(int j = 0; j < 1<<m; ++j){
                int sum = 0;
                for(int k = 0; k < m; ++k){
                    if((1<<k)&j) sum += quantity[k];
                }
                if(sum <= arr[i]) ok[i][j] = true;
            }
            for(unsigned int j = 0; j < 1<<m; ++j){
                dp[i][j] = dp[i+1][j];
                unsigned int mask = (~j) & ((1<<m)-1);
                for(int submask = mask; submask; submask = (submask-1)&mask){
                    if(ok[i][submask]) dp[i][j] |= dp[i+1][j|submask];
                }
            }
        }
        return dp[0][0];
    }
};

// Bottom up O(nm3^m). slow. different from above is when generate submask
// loop m.
class Solution {
public:
    vector<int> arr;
    bool dp[55][1<<10];
    int n, m;
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        memset(dp, 0, sizeof dp);;
        unordered_map<int, int> mp;
        for(auto &x: nums) mp[x]++;
        for(auto &[a, b]: mp) arr.push_back(b);

        n = arr.size();
        m = quantity.size();
        dp[n][(1<<m)-1] = 1;
        
        for(int i = n-1; i >= 0; --i){
            for(unsigned int j = 0; j < 1<<m; ++j){
                dp[i][j] = dp[i+1][j];
                unsigned int mask = (~j) & ((1<<m)-1);
                for(int submask = mask; submask; submask = (submask-1)&mask){
                    int sum = 0;
                    for(int k = 0; k < m; ++k){
                        if((1<<k)&submask) sum += quantity[k];
                    }
                    if(sum <= arr[i]) dp[i][j] |= dp[i+1][j|submask];
                }
            }
        }
        
        return dp[0][0];
    }
};
