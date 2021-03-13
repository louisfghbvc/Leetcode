// Sort array. and use dp + binary search.
// O(N^2logN)
class Solution {
public:
    const int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        vector<int> dp(n, 1);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(arr[i] % arr[j] == 0){
                    int tar = arr[i]/arr[j];
                    auto p = lower_bound(arr.begin(), arr.begin()+i, tar);
                    if(p != arr.end() && *p == tar){
                        dp[i] = (dp[i] + 1LL * dp[p-arr.begin()] * dp[j]) % mod;
                    }
                }
            }
        }
        
        int res = 0;
        for(int &x: dp){
            res = (res+x) % mod;
        }
        return res;
    }
};

// Use hashtable record index.
// O(N^2).
class Solution {
public:
    const int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        vector<int> dp(n, 1);
        
        unordered_map<int, int> idx;
        for(int i = 0; i < n; ++i)
            idx[arr[i]] = i; 
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(arr[i] % arr[j] == 0){
                    int tar = arr[i]/arr[j];
                    if(idx.count(tar)){
                        dp[i] = (dp[i] + 1LL * dp[idx[tar]] * dp[j]) % mod;
                    }
                }
            }
        }
        
        int res = 0;
        for(int &x: dp){
            res = (res+x) % mod;
        }
        return res;
    }
};

// DP as hash table. O(N^2).
class Solution {
public:
    const int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int res = 0;
        unordered_map<int, int> dp;
        for(int i = 0; i < n; ++i){
            dp[arr[i]] = 1;
            for(int j = 0; j < i; ++j){
                if(arr[i] % arr[j] == 0){
                    int tar = arr[i]/arr[j];
                    if(dp.count(tar)){
                        dp[arr[i]] = (dp[arr[i]] + 1LL * dp[tar] * dp[arr[j]]) % mod;
                    }
                }
            }
            res = (res+dp[arr[i]])%mod;
        }
        
        return res;
    }
};
