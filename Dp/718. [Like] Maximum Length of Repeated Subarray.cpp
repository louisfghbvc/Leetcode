// O(N^2). Easy dp
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        int mx = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
    }
};

// Rolling hash + Binary Search.
// O(NlogN)

class Solution {
public:
    const int d = 256, mod = 1e9+7;
    
    unordered_set<int> get_hash(vector<int> &A, int K){
        unordered_set<int> st; // hash value of A
        
        long h = 1; 
        for(int i = 1; i < K; ++i)
            h = h * d % mod;
        
        long hash = 0;
        for(int i = 0; i < A.size(); ++i){
            if(i >= K){
                hash = (hash - h * A[i-K] % mod + mod) % mod;
            }
            hash = (hash * d + A[i]) % mod;
            if(i >= K-1) st.insert(hash);
        }
        
        return st;
    }
    
    bool findK(int K, vector<int> &A, vector<int> &B){
        if(K == 0) return true;
        auto L = get_hash(A, K);
        auto R = get_hash(B, K);
        for(auto &x: L)
            if(R.count(x)) return true;
        return false;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = min(nums1.size(), nums2.size());
        int ans =  0;
        while(l <= r){
            int mid = (l+r) / 2;
            if(findK(mid, nums1, nums2)) l = mid+1, ans = mid;
            else r = mid-1;
        }
        return ans;
    }
};
