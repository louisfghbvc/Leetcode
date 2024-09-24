class Solution {
public:

    int jumpGame(vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        int cur = 0, nxt = -1;
        for (int i = 0; i < n; ++i) {
            nxt = max(nxt, arr[i]);
            if (i == cur) { // reach cur max
                if (nxt == -1) return -1; // no next 
                res++;
                cur = nxt+1;
                nxt = -1;
            }
        }
        return cur >= n ? res : -1;
    }

    int minValidStrings(vector<string>& words, string target) {
        // goal: find the minimum string to split the target each word is a prefix
        
        // idea:
        // for each index we can compute the maximum jump
        // convert to jump game => segment [i, i+jump[i]]
        // in the segment we need to find out the maximum jump to be the next start point
        // [     ]
        //   [     ]
        //     [ ]
        // each index, we using binary search to find out the maximum length

        using hash_t = unsigned long long;
        int mx = 0;
        for (auto &s: words)
            mx = max(mx, (int)s.size());
        mx = max(mx, (int)target.size());
        vector<unordered_set<hash_t>> group(mx+1); // group by length, each is hash
        for (auto &s: words) {
            hash_t val = 0;
            int len = 0;
            for (char c: s) {
                val = val * 37 + c - 'a';
                len++;
                group[len].insert(val);
            }
        }

        int n = target.size();

        // compute the hash of target
        vector<hash_t> pre(n), powB(n+1, 1);
        auto getHash = [&](int l, int r) {
            if (l == 0) return pre[r];
            return pre[r] - pre[l-1] * powB[r-l+1];
        };
        for (int i = 1; i <= n; ++i)
            powB[i] = powB[i-1]*37;

        for (int i = 0; i < n; ++i) {
            pre[i] = target[i]-'a';
            if (i > 0)
                pre[i] += pre[i-1]*37;
        }

        auto getFar = [&](int i) {
            int l = i, r = n-1;
            int ans = -1;
            while (l <= r) {
                int m = (l+r)/2;
                int len = m - i + 1;
                if (group[len].count(getHash(i, m))) ans = m, l = m+1;
                else r = m-1;
            }
            return ans;
        };

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) 
            arr[i] = getFar(i);

        return jumpGame(arr);
    }
};
