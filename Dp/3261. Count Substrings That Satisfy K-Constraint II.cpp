class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        // goal: count the substring that is good, do each query
        
        // idea: 
        // record left[i]: mininimum left such that [left[i], i] is good
        // record pre[i]: ending at index i, sum of goods
        
        // if left[r] <= l => means [l, r] all good!
        // sum = 1 + 2 + ... r-l+1
        // else:
        // find out first left[j] >= l, using binary search
        // [l, j-1] => all goods, since left[j-1] <= l 
        // 1 + 2 + ... j-l
        // [j, r] => using prefix sum

        int n = s.size();
        int cnt[2]{};

        vector<long> pre(n+1), left(n);
        for (int r = 0, l = 0; r < n; ++r) {
            cnt[s[r]-'0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l++]-'0']--;
            }
            left[r] = l;
            pre[r+1] = pre[r] + r-l+1;
        }

        vector<long long> res;
        for (auto &q: queries) {
            long l = q[0], r = q[1];
            if (left[r] <= l) {
                res.push_back((r-l+2)*(r-l+1)/2);
            }
            else {
                int j = lower_bound(left.begin(), left.begin()+r+1, l) - left.begin();
                long tmp = (long)(j-l+1)*(j-l)/2;
                tmp += pre[r+1] - pre[j];
                res.push_back(tmp);
            }
        }

        return res;
    }
};
