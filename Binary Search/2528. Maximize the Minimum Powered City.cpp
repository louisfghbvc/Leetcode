class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        // goal: k -> can add any stations, maximum the total power
        // idea: 
        // [1,2,4,5,0], calculate the prefix and suffix of range r, sliding window - self is duplicate
        //  3,7,11,9,5 -> fix
        //. 2,     -2
        //. 0+2*r+1=3
        // need=2
        // k-2
        //  5,9,13,9,5,
        
        //  
        // binary search
        // how to range add -> line sweep
        // add i += remain
        // add i+2*r+1 -= remain
        
        int n = stations.size();
        vector<long> power(n); 
        // window size is r+1
        {
            long sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += stations[i];
                power[i] += sum;
                if (i >= r) {
                    sum -= stations[i-r];
                }
            }
        }
        
        // suffix -> reverse -> prefix
        reverse(stations.begin(), stations.end());
        reverse(power.begin(), power.end());
        {
            long sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += stations[i];
                power[i] += sum;
                if (i >= r) {
                    sum -= stations[i-r];
                }
            }
        }
        reverse(stations.begin(), stations.end());
        reverse(power.begin(), power.end());
        for (int i = 0; i < n; ++i)
            power[i] -= stations[i];
        
        // for (int i = 0; i < n; ++i)
        //     cout << power[i] << ' ';
        // cout << '\n';
        
        auto good = [&](long mid) {
            vector<long> add(4*n); // dummy
            long ops = 0;
            long rolling = 0;
            for (int i = 0; i < n; ++i) {
                rolling += add[i];
                long tmp = power[i] + rolling;
                if (tmp < mid) { // need add
                    long need = mid - tmp;
                    ops += need;
                    rolling += need;
                    add[i+2*r+1] -= need;
                    if (ops > k) return false; // early stop
                }
            }
            return ops <= k;
        };
        
        long ans = 0;
        long L = 0, R = (long)1e14+5;
        while (L <= R) {
            long mid = (L+R)/2;
            if (good(mid)) ans = mid, L = mid+1;
            else R = mid-1;
        }
        return ans;
    }
};
