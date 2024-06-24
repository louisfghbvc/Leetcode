class Solution {
public:

    vector<int> tree;
    void build(vector<int> &arr, int id, int l, int r) {
        if (l == r) {
            tree[id] = arr[l];
            return;
        }
        int m = (l+r)/2;
        build(arr, id*2+1, l, m);
        build(arr, id*2+2, m+1, r);
        tree[id] = tree[id*2+1] + tree[id*2+2];
    }
    int query(int id, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) return tree[id];
        if (r < ll || l > rr) return 0;
        int m = (l+r)/2;
        return query(id*2+1, l, m, ll, rr) + query(id*2+2, m+1, r, ll, rr);
    }
    void update(int id, int l, int r, int x, int val) {
        if (r < x || l > x) return;
        if (x <= l && r <= x) {
            tree[id] = val;
            return;
        }
        int m = (l+r)/2;
        update(id*2+1, l, m, x, val);
        update(id*2+2, m+1, r, x, val);
        tree[id] = tree[id*2+1] + tree[id*2+2];
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        // goal: count the peaks
        // idea:
        // using segment tree
        // preprocessing the peak array first
        // doing the segment tree

        int n = nums.size();
        vector<int> peak(n);
        for (int i = 1; i+1 < n; ++i)
            peak[i] = nums[i] > nums[i-1] && nums[i] > nums[i+1];

        tree.assign(4*n, 0);
        build(peak, 0, 0, n-1);

        vector<int> res;
        for (auto &q: queries) {
            if (q[0] == 1) {
                int tmp = query(0, 0, n-1, q[1], q[2]);
                if (peak[q[1]]) tmp--;
                if (q[2] != q[1] && peak[q[2]]) tmp--;
                res.push_back(tmp);
            }
            else { // update
                nums[q[1]] = q[2];
                for (int i = max(0, q[1]-1); i <= min(q[1]+1, n-1); ++i) {
                    if (i == 0 || i == n-1) continue;
                    peak[i] = nums[i] > nums[i-1] && nums[i] > nums[i+1];
                    update(0, 0, n-1, i, peak[i]);
                }
            }
        }

        return res;
    }
};
