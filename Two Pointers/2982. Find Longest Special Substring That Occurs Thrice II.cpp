// Only Track Max frequency of each letter.
// TC: O(n), SC: O(1)

class Solution {
public:
    int maximumLength(string s) {
        // goal: find the maximum special string that occur at least three times
        // idea:
        // TC: O(n^2) => TLE
        // aaaa, ans=2

        // math =>
        // aaaa, ans=2, (4, 2)
        // aaaaa, ans=3, (5, 3)
        // ans = max fre - 2
        // we just try 2 case!
        // possible: max fre - 1, max fre
        // F(len) => existed length at least len 3 times!

        int cnt[26]{};
        int n = s.size();
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && s[i] == s[j]) j++;
            cnt[s[i]-'a'] = max(cnt[s[i]-'a'], j-i);
        }

        int mx = *max_element(cnt, cnt+26);
        int ans = mx - 2;

        // only 2 loop
        for (int len = ans+1; len <= mx; ++len) {
            int tmp[26]{};
            for (int i = 0, j; i < n; i = j) {
                j = i;
                while (j < n && s[i] == s[j]) j++;
                // how many strings greater than len
                tmp[s[i]-'a'] += max(0, j-i-len+1);
            }   

            // update ans
            for (int i = 0; i < 26; ++i)
                if (tmp[i] >= 3)
                    ans = len;
        }

        if (ans <= 0) ans = -1;
        return ans;
    }
};
