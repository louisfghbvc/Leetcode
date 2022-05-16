// Solution1: sliding window
// note! need to reverse to avoid the case abbb...
// O(26^2n)

class Solution {
public:
    int largestVariance(string s) {
        // goal: calculate the largestVariance, occurrence of any two occ
        // idea: enumerate the possible pair of chars
        
        int n = s.size();
        unordered_set<char> st(s.begin(), s.end()); // appear in s
        
        auto cal = [&](char a, char b) { // maintain a occ >= b occ
            int res = 0;
            int a_occ = 0, b_occ = 0;
            for (int r = 0, l = 0; r < n; ++r) {
                a_occ += s[r] == a;
                b_occ += s[r] == b;
                while (l <= r && a_occ < b_occ) {
                    a_occ -= s[l] == a;
                    b_occ -= s[l] == b;
                    l++;
                }
                if (a_occ && b_occ)
                    res = max(a_occ - b_occ, res);
            }
            return res;
        };
        
        int ans = 0;
        for (char i = 'a'; i <= 'z'; ++i) {
            if (!st.count(i)) continue;
            for (char j = 'a'; j <= 'z'; ++j) {
                if (i == j || !st.count(j)) continue;
                ans = max(cal(i, j), ans);
            }
        }
        
        reverse(s.begin(), s.end());
        for (char i = 'a'; i <= 'z'; ++i) {
            if (!st.count(i)) continue;
            for (char j = 'a'; j <= 'z'; ++j) {
                if (i == j || !st.count(j)) continue;
                ans = max(cal(i, j), ans);
            }
        }
        
        return ans;
    }
};

// Solution 2
// Dp, maximum subarray tweak.
