// LCS, Dp use BIT
// tricky. build from length 1 to length 3

class Solution {
    struct BIT{
        vector<long> arr;
        int N;
        
        BIT(int n) : N(n+1), arr(n+1){}
        
        void clear(){
            arr.assign(N, 0);
        }
        
        void add(int x, long v){
            for(++x; x < N; x += x&-x)
                arr[x] += v;
        }
        
        long query(int x){
            long res = 0;
            for(++x; x; x -= x&-x)
                res += arr[x];
            return res;
        }
    };

public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        BIT tree(n);
        
        // find all length lcs = 3 -> convert to lis
        vector<int> indexNums1(n);
        for(int i = 0; i < n; ++i)
            indexNums1[nums1[i]] = i;
        
        vector<long> dp(n, 1);
        for(int l = 1; l < 3; ++l){
            vector<long> ndp(n);
            tree.clear();
            for(int i = 0; i < n; ++i){
                int pos = indexNums1[nums2[i]];
                ndp[i] = tree.query(pos);
                tree.add(pos, dp[i]);
            }
            dp = move(ndp);
        }
        
        return accumulate(dp.begin(), dp.end(), 0LL);
    }
};
