class Solution {
public:

    struct BIT {
        int N;
        vector<int> arr;
        BIT (int n) : N(n+1), arr(N, 0) {}
        void add(int x, int v) {
            for (++x; x < N; x += x&-x)
                arr[x] += v;
        }
        int sum(int x) {
            int ans = 0;
            for (++x; x > 0; x -= x&-x)
                ans += arr[x];
            return ans;
        }
    };
    
    long long minInversionCount(vector<int>& nums, int k) {
        // goal: 
        // find out all subarray length k inversion count
        
        // idea:
        // BIT + sliding window
        int n = nums.size();
        
        BIT tree(n);
        auto tmp = nums;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        auto get = [&](int x) {
            return lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();    
        };
        
        long ans = LLONG_MAX;
        long cnt = 0;
        for (int i = 0; i < n; ++i) {
            int id = get(nums[i]);
            int great = tree.sum(n-1) - tree.sum(id); // > x
            cnt += great;
            tree.add(id, 1);
            if (i >= k-1) {
                // compute ans
                ans = min(ans, cnt);

                // remove window
                int y = get(nums[i-k+1]);
                tree.add(y, -1);
                cnt -= tree.sum(y-1); // in window the number of smaller would remove inv count
            }
        }        
        return ans;
    }
};
