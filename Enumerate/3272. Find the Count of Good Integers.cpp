class Solution {
public:    
    long long countGoodIntegers(int n, int k) {
        // goal: count the good int such that is divisible by k and is palindrome (rearrange)
        // idea: digit dp
        // enumerate each bit
        // dfs(i, sum)
        // we also can rearrange
        // if we determine a palidrome 
        // k=1
        // e.g 2002
        
        // idea2:
        // we can enumerate first half => only 5 digits!
        // O (10^5 * 10) => may be can try brute force?
        // we generate the each distinct palindrome divisible by k!!!
        // using set, after that => for each distinct we can just find the comb
        
        // init
        int half = (n+1)/2;
        vector<long> fac(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i-1] * i;
        }
        
        // 1 2 3

        set<array<int, 10>> tot;
        int bound = pow(10, half);
        for (int i = 1; i < bound; ++i) {
            string s = to_string(i);
            string r = s;
            if (n & 1) r.pop_back();
            s += string(r.rbegin(), r.rend());
            if (s.size() == n && stoll(s) % k == 0) {
                array<int, 10> cur{};
                for (char c: s)
                    cur[c-'0']++;
                tot.insert(cur);
            }
        }
        
        long long ans = 0;
        for (auto &cnt: tot) {
            int sum = 0;
            for (int x: cnt)
                sum += x;

            long tmp = fac[sum];
            for (int x: cnt)
                tmp /= fac[x];
            ans += tmp;
            
            if (cnt[0]) {
                tmp = fac[sum-1];
                for (int i = 0; i < 10; ++i) {
                    if (i == 0)
                        tmp /= fac[cnt[i]-1];
                    else
                        tmp /= fac[cnt[i]];
                }
                ans -= tmp;
            }
        }
        
        return ans;
    }
};
