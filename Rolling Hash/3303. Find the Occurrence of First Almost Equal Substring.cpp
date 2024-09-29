class Solution {
public:
    
    int minStartingIndex(string s, string pattern) {
        // goal: find the minimum starting index such that we can change at most 1 pattern
        // idea:
        
        // we can just using kmp search?
        // pattern => build lps table
        
        // s => we are doing the failing link in 26 times
        // we need to record the changed, and last index of all letters
        
        // idea2: rolling hash?
        // we can record all 26N hashset

        // 26N hash set too slow => we can just record n hash ... wtf
        // and enumerate the pattern check out if we have hash value
        
        // n = 3
        // a b c
        // a*B^2 + b*B^1 + c
        
        using hash_t = unsigned long long;
        
        int m = s.size();
        int n = pattern.size();
        
        hash_t B = 37;
        
        // init
        vector<hash_t> powB(n+1, 1);
        for (int i = 1; i <= n; ++i)
            powB[i] = powB[i-1] * B;
        
        // record the hashmap => hash -> min start index
        unordered_map<hash_t, int> mp;
        hash_t cur = 0;
        for (int i = 0; i < m; ++i) {
            cur = cur * B + s[i]-'a';
            if (i >= n-1) {
                if (!mp.count(cur))
                    mp[cur] = i-(n-1);
                cur -= powB[n-1] * (s[i-(n-1)]-'a');
            }
        }

        // init pattern
        hash_t val = 0;
        for (char c: pattern)
            val = val * B + c - 'a';
        
        int ans = m;
        for (int i = 0; i < n; ++i) {
            int old = pattern[i]-'a';
            for (int j = 0; j < 26; ++j) {
                // cout << old << ' ' << j << '\n';
                hash_t next = val + powB[n-1-i] * (j - old);
                auto it = mp.find(next);
                if (it != mp.end()) {
                    ans = min(ans, it->second);
                }
            }
        }
        
        return ans >= m ? -1 : ans;
    }
};
