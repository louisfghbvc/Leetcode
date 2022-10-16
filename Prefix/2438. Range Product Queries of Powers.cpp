class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // goal: try to get the products
        // idea: generate the powers, and brute force the queries, range is small
        
        vector<int> powers;
        for (int i = 0; i < 31; ++i)
            if (n >> i & 1)
                powers.push_back(1<<i);
        
        vector<int> res;
        const int mod = 1e9+7;
        for (auto &q: queries) {
            long cur = 1;
            for (int i = q[0]; i <= q[1]; ++i) {
                cur = cur * powers[i] % mod;
            }
            res.push_back(cur);
        }
        
        return res;
    }
};
