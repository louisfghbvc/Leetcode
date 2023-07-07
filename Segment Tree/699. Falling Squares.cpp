class Solution {
public:

    struct node {
        node *l = nullptr, *r = nullptr;
        int s, e;
        int val = 0;
        int lazy = 0;
        node (int s, int e, int val=0) : s(s), e(e), val(val) {}
        node* getL() {
            if (!l) l = new node(s, s+(e-s)/2);
            return l;
        }
        node* getR() {
            if (!r) r = new node(s+(e-s)/2+1, e);
            return r;
        }
        void pushDown() {
            if (lazy == 0 || s == e) return;
            getL()->val = lazy;
            getL()->lazy = lazy;
            getR()->val = lazy;
            getR()->lazy = lazy;
            lazy = 0;
        }
    };

    int query(node* cur, int l, int r) {
        if (cur->e < l || r < cur->s) return 0;
        if (l <= cur->s && cur->e <= r) return cur->val;
        cur->pushDown();
        return max(query(cur->getL(), l, r), query(cur->getR(), l, r));
    }

    void update(node* cur, int l, int r, int val) {
        if (cur->e < l || r < cur->s) return;
        if (l <= cur->s && cur->e <= r) {
            cur->val = val;
            cur->lazy = val;
            return;
        }
        cur->pushDown();
        update(cur->getL(), l, r, val);
        update(cur->getR(), l, r, val);
        cur->val = max(cur->getL()->val, cur->getR()->val);
    }

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        // goal: for each square, find the maximum height after down
        // idea: 

        // 1 <= positions.size() <= 1e3
        // 1 <= positions[i][0], lefti <= 10^8
        // 1 <= positions[i][1], sidei <= 10^6

        
        // segment tree -> record x axis
        // tree[id] -> [l, r] maximum height? 
        // update range O(logMAX),

        int bound = 0;
        for (auto &p : positions)
            bound = max(bound, p[0] + p[1]);
        node* root = new node(0, bound);

        vector<int> ans;
        for (auto &p: positions) {
            int max_height = query(root, p[0], p[0]+p[1]-1);
            update(root, p[0], p[0]+p[1]-1, max_height+p[1]);
            ans.push_back(root->val);
        }
        return ans;
    }
};
