class Solution {
public:
    string toBin(int x) {
        string s;
        while (x) {
            s.push_back('0' + (x & 1));
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s == "" ? "0" : s;
    }

    // 由 prefix + 長度 L 建構二進位回文
    long long buildPal(const string &pre, int L) {
        string rev = pre;
        reverse(rev.begin(), rev.end());

        string s = pre;
        if (L % 2 == 1) s += rev.substr(1);
        else s += rev;

        if (s[0] == '0') return -1;  // no leading zero

        return stoll(s, nullptr, 2);
    }

    vector<long long> candidates(int x) {
        vector<long long> res;
        string sx = toBin(x);
        int L = sx.size();

        for (int len = L - 1; len <= L + 1; ++len) {
            if (len <= 0) continue;

            int half = (len + 1) / 2;

            // 取 prefix：如果 x 不夠長，左邊補 0
            string full = sx;
            while ((int)full.size() < L) full = "0" + full;

            string prefix = full.substr(0, min(half, L));
            long long p = stoll(prefix, nullptr, 2);

            for (long long t : {p - 1, p, p + 1}) {
                if (t <= 0) continue;

                string pt = toBin(t);
                if ((int)pt.size() != half) continue;

                long long pal = buildPal(pt, len);
                if (pal > 0) res.push_back(pal);
            }
        }
        return res;
    }

    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            auto cand = candidates(x);

            long long best = LLONG_MAX;
            for (long long p : cand) {
                best = min(best, llabs(p - x));
            }
            ans[i] = best;
        }
        return ans;
    }
};
