// Binary Search + Prefix sum. O(MlogN). Can optimal no use map.

class Solution {
public:
    const int mod = 1e9+7;
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size();
        
        sort(packages.begin(), packages.end());
        for(auto &b: boxes)
            sort(b.begin(), b.end());
        
        vector<long> pre(n+1);
        
        map<int, int> mp;
        for(int i = 1; i <= n; ++i){
            pre[i] += pre[i-1] + packages[i-1];
            mp[packages[i-1]] = i;
        }

        long res = LLONG_MAX;
        bool ok = 0;
        for(auto &b: boxes){
            if(b.back() < packages.back()) continue;
            long loc_sum = 0;
            int last = 0;
            ok = 1;
            for(int x: b){
                auto p = mp.upper_bound(x);
                if(p == mp.begin()) continue;
                p = prev(p);
                long num = p->second - last;
                long sum = pre[p->second] - pre[last]; 
                loc_sum += x * num - sum;
                last = p->second;
                if(p == prev(mp.end())) break;
            }
            res = min(res, loc_sum);
        }
        
        return ok ? res % mod : -1;
    }
};
