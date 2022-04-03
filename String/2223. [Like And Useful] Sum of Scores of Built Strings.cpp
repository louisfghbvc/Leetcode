class Solution {
public:
        
    long long sumScores(string s) {
        int n = s.size();
        
        // goal: idea z-algorithm
        
        vector<long> z(n);
        z[0] = n;
        
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) 
                z[i] = min((long)r - i + 1, z[i-l]);
            while (i + z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        
        return accumulate(z.begin(), z.end(), 0L);
    }
};
