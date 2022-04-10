// O(NlogN + Nlognlogx)

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        // goal: maximum the beauty min of flowers * partial and number of complete * full
        
        // idea: enumerate the complete numbers
        // for each complete number, binary search the min that we can get
        // build the prefix sum, 
        // enumerate from [0, n] see if we can reach complete number
        // see the suffix -> compute the number we need to add, to make each at least target
        
        sort(flowers.begin(), flowers.end());
        long base = 0;
        while (flowers.size() && flowers.back() >= target) {
            base += full;
            flowers.pop_back();
        }
        if (flowers.empty()) return base;
        
        int n = flowers.size();
        vector<long> pre(n+1);
        for (int i = 0; i < n; ++i)
            pre[i+1] = pre[i] + flowers[i];
        
        // can flower [0, r) can reach x
        auto can = [&](long x, int r) {
            if (r == 0) return false;
            int pos = upper_bound(flowers.begin(), flowers.begin() + r, x) - flowers.begin();
            return x * pos - pre[pos] <= newFlowers; 
        };
        
        // maximum the partial
        auto f = [&](int bound) {
            long l = 0, r = target-1;
            long ans = 0;
            while (l <= r) {
                long mid = (l+r)/2;
                if (can(mid, bound)) ans = mid, l = mid+1;
                else r = mid-1;
            }
            return ans*partial;
        };
                
        long ans = f(n); // no add
        for (int i = 1; i <= n; ++i) {
            // bring the topmost to target
            long right = (long)target*i - (pre.back() - pre[n-i]);
            if (right > newFlowers) continue;
            newFlowers -= right;
            ans = max(ans, (long)full * i + f(n-i));
            newFlowers += right;
        }
        
        return base + ans;
    }
};
