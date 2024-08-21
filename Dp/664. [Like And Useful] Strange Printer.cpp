class Solution {
public:
    int strangePrinter(string s) {
        // goal: find out the minimum number of print to make to string
        // print we can choose [l, r] -> print a letter

        // idea:
        // e.g
        // aba => aaa
        //         b
        // a a a a
        //   b b
        //   c

        //.       l
        //.         r
        // [a b a c a]
        //  ^   ^   ^
        //  a b c

        // a b c a b s b
        // ^     ^

        // a b c a b c a
        // 

        // dp
        // dfs(i, j): minimum turn to make s[i:j] paint
        // we always need paint first letter s[i]
        // each [i, j] we use two pointers to record window that is not s[i]

        // after looking the solution
        // we can just consider s[l] == s[r]
        // if s[l] == s[r] => dfs(l, r-1), since r can always be done with no cost
        // else
        // enumerate the middle 

        int n = s.size();
        vector dp(n, vector(n, -1));
        auto dfs = [&](auto &self, int l, int r) -> int {
            if (l > r) return 0;
            if (l == r) return 1;

            int &res = dp[l][r];
            if (res != -1) return res;

            res = n;
            if (s[l] == s[r])
                res = self(self, l, r-1);
            else {
                for (int k = l; k < r; ++k)
                    res = min(res, self(self, l, k) + self(self, k+1, r));
            }

            return res;
        };

        return dfs(dfs, 0, n-1);
    }
};
