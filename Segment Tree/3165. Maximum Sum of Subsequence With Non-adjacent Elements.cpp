
class Solution {
public:
    struct node {
        long val[2][2]{}; // first: left choose or not, second: right choose or not
        node(int v=0) { // single node
            // val[1][0] = val[0][1] = -1e18;
            val[1][1] = v;
        }
        node operator+(const node& other) {
            node res;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    res.val[i][j] = max({this->val[i][0] + other.val[0][j], this->val[i][0] + other.val[1][j], this->val[i][1] + other.val[0][j]});
                }
            }
            return res;
        }
    };  
    
    vector<node> tree;
    void build(vector<int> &arr, int id, int l, int r) {
        if (l == r) {
            tree[id] = node(arr[l]);
            return;
        }
        int m = (l+r)/2;
        build(arr, id*2+1, l, m);
        build(arr, id*2+2, m+1, r);
        tree[id] = tree[id*2+1] + tree[id*2+2];
    };

    void update(int p, int x, int id, int l, int r) {
        if (r < p || l > p) return;
        if (l == r) {
            tree[id].val[1][1] = x;
            return;
        }
        int m = (l+r)/2;
        update(p, x, id*2+1, l, m);
        update(p, x, id*2+2, m+1, r);
        tree[id] = tree[id*2+1] + tree[id*2+2];
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        // idea: use segment tree to store the value of choose or not
        // Note!!!: single node we need to care is that only [1][1] has value
        // stuck in here, and stuck in the state
        // just think a segment inside a single node: 4 types, heads or not * tails or not

        int n = nums.size();
        tree.resize(4*n);
        build(nums, 0, 0, n-1);
        
        int mod = 1e9+7;
        long res = 0;
        for (auto &q: queries) {
            update(q[0], q[1], 0, 0, n-1);
            long mx = max({tree[0].val[0][0], tree[0].val[0][1], tree[0].val[1][0], tree[0].val[1][1]});
            res = (res + mx) % mod;
        }

        return res;
    }
};
