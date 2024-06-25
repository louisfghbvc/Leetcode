class Solution {
public:

    struct node {
        long val = 0;
        int lazyTag = 0;
    };
    
    vector<node> tree;
    void build(vector<int> &arr, int id, int l, int r) {
        if (l == r) {
            tree[id].val = arr[l];
            return;
        }
        int m = (l+r)/2;
        build(arr, id*2+1, l, m);
        build(arr, id*2+2, m+1, r);
        tree[id].val = tree[id*2+1].val + tree[id*2+2].val;
    }

    void update(int id, int l, int r, int ll, int rr) {
        push(id, l, r);
        if (r < ll || l > rr) return;
        if (ll <= l && r <= rr) {
            tree[id].val = (r-l+1) - tree[id].val;
            tree[id].lazyTag ^= 1;
            return;
        }
        int m = (l+r)/2;
        update(id*2+1, l, m, ll, rr);
        update(id*2+2, m+1, r, ll, rr);
        tree[id].val = tree[id*2+1].val + tree[id*2+2].val;
    }

    void push(int id, int l, int r) {
        if (l == r) return;
        if (!tree[id].lazyTag) return;
        tree[id].lazyTag = 0;
        int m = (l+r)/2;
        tree[id*2+1].lazyTag ^= 1;
        tree[id*2+1].val = (m-l+1) - tree[id*2+1].val;
        tree[id*2+2].lazyTag ^= 1;
        tree[id*2+2].val = (r-m) - tree[id*2+2].val;
    }

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        // idea: lazy segment tree
        // 1. maintain nums2 value, nums1
        // 2. for op1, we need to flip the nums1 (using lazy tag) -> range update
        // 3. for op2, always do all nums2, actually it will increase the sum(nums1) * p
        // 4. for op3, get the total sum

        int n = nums1.size();
        tree.resize(4*n);

        build(nums1, 0, 0, n-1);

        long sum = accumulate(nums2.begin(), nums2.end(), 0L);

        vector<long long> res;
        for (auto &q: queries) {
            if (q[0] == 1) {
                update(0, 0, n-1, q[1], q[2]);
            }
            else if (q[0] == 2) {
                sum += tree[0].val * q[1];
            }
            else {
                res.push_back(sum);
            }
        }

        return res;
    }
};
