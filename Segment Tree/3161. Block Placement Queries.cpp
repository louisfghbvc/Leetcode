// Approach1. Segment Tree with point update, range query
class Solution {
public:
    
    vector<int> tree;
    void update(int p, int x, int id, int l, int r) {
        if (r < p || l > p) return;
        if (l == r) {
            tree[id] = x;
            return;
        }
        int m = (l+r)/2;
        update(p, x, id*2+1, l, m);
        update(p, x, id*2+2, m+1, r);
        tree[id] = max(tree[id*2+1], tree[id*2+2]);
    }
    
    int query(int L, int R, int id, int l, int r) {
        if (r < L || l > R) return 0;
        if (L <= l && r <= R) return tree[id];
        int m = (l+r)/2;
        return max(query(L, R, id*2+1, l, m), query(L, R, id*2+2, m+1, r));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        // goal: find if can place block
        // idea:
        // record obstacle, find the last one -> using set
        // record the maximum size [0,x] -> [0,x] is 3, [x+1, ~] > 3
        // using segment tree, update the point max
        
        int n = 5e4 + 5;
        tree.resize(4*n);
        
        vector<bool> res;
        set<int> ob = {0};
        for (auto &q: queries) {
            if (q[0] == 1) {
                auto it = prev(ob.lower_bound(q[1]));
                update(q[1], q[1]-*it, 0, 0, n-1);
                if (next(it) != ob.end())
                    update(*next(it), (*next(it))-q[1], 0, 0, n-1);
                ob.insert(q[1]);
            }
            else {
                int len = query(0, q[1], 0, 0, n-1);
                auto it = prev(ob.upper_bound(q[1]));
                len = max(len, q[1]-*it);
                res.push_back(q[2] <= len);
            }
        }
        return res;
    }
};

// Approach2, BIT with reverse order. trick
// In set, we also can add dummy maximum
class Solution {
public:
    
    struct BIT {
        vector<int> arr;
        int N;
        BIT (int n) : N(n+1), arr(n+1) {}
        void update(int x, int v) {
            for (++x; x < N; x+=x&-x)
                arr[x] = max(arr[x], v);
        }
        int query(int x) {
            int res = 0;
            for (++x; x; x-=x&-x)
                res = max(arr[x], res);
            return res;
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        // goal: find if can place block
        // idea:
        // do it reverse, make max increasing.
        // record obstacle, find the last one -> using set
        // type1 -> update BIT
        // type2 -> query
        
        int n = 5e4 + 5;
        BIT tree(n);
        
        vector<bool> res;
        set<int> ob = {0};
        for (auto &q: queries)
            if (q[0] == 1)
                ob.insert(q[1]);
        
        // pre-compute the maximum
        for (auto it = next(ob.begin()); it != ob.end(); ++it)
            tree.update(*it, *it-*prev(it));

        reverse(queries.begin(), queries.end());
        for (auto &q: queries) {
            if (q[0] == 1) { // update, remove q[1]
                auto it = ob.lower_bound(q[1]);
                if (next(it) != ob.end())
                    tree.update(*next(it), (*next(it))-*prev(it));
                ob.erase(q[1]);
            }
            else {
                int len = tree.query(q[1]);
                auto it = prev(ob.upper_bound(q[1]));
                len = max(len, q[1]-*it);
                res.push_back(q[2] <= len);
            }
        }

        return vector<bool>(res.rbegin(), res.rend());
    }
};
