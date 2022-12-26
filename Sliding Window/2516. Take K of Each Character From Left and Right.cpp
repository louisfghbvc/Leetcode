class Solution {
public:
    int takeCharacters(string s, int k) {
        // goal: minimum the minutes such that each letter is at least k
        // idea: 
        
        // [aab]aaaa]caabc), k=2
        //     xxxxxxxxxxx
        // calculate each letter counting
        // a = 8
        // b = 2
        // c = 2
        
        // two pointers
        
        int cnt[3] = {};
        for (char c: s)
            cnt[c-'a']++;
        
        vector<int> arr(3);
        auto good = [&]() {
            for (int i = 0; i < 3; ++i)
                if (cnt[i] - arr[i] < k)
                    return false;
            return true;
        };
        
        if (!good()) return -1; // base case, all should >= k
        
        int n = s.size();
        int ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            arr[s[r]-'a']++;
            while (l <= r && !good()) {
                arr[s[l]-'a']--;
                l++;
            }
            if (l <= r) {
                ans = max(ans, r-l+1);
            }
        }
        
        return n - ans;
    }
};
