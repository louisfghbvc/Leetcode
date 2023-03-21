// solution1: greedy
class Solution {
public:
    
    int findMinimumTime(vector<vector<int>>& tasks) {
        // goal: find the minimum time to finish all tasks
        // idea:
        // greedy

        // sort by end
        sort(tasks.begin(), tasks.end(), [&](auto &a, auto &b){
            return a[1] < b[1];
        });

        vector<bool> on(2001);
        for (auto &t: tasks) {
            int l = t[0], r = t[1], d = t[2];
            d -= count(on.begin()+l, on.begin()+r+1, true);
            for (int i = r; d > 0; --i) { // put from backwards
                if (!on[i]) d--;
                on[i] = true;
            }
        }

        return count(on.begin(), on.end(), true);
    }
};

// Solution2: segment tree

class Solution {
public:
    
    struct node {
        node(int _l, int _r) : l(_l), r(_r) {}
        void push() {
            int m = (l+r)>>1;
            if (!left) left = new node(l, m);
            if (!right) right = new node(m+1, r);
            if (todo) {
                todo = false;
                left->todo = true;
                right->todo = true;
                left->cnt = m-l+1;
                right->cnt = r-(m+1)+1;
            }
        }
        void pull() {
            cnt = left->cnt+right->cnt;
        }
        int l, r;
        node *left = nullptr, *right = nullptr;
        bool todo = false;
        int cnt = 0;
    };

    int suffix;
    int query(node* root, int L, int R) {
        if (L > root->r || R < root->l) return 0;
        if (L <= root->l && root->r <= R) return root->cnt;
        root->push();
        return query(root->left, L, R) + query(root->right, L, R);
    }
    void update(node* root, int L, int R) {
        if (L > root->r || R < root->l || suffix == 0) return;
        int remain = root->r-root->l+1-root->cnt;
        if (L <= root->l && root->r <= R && remain <= suffix) {
            suffix -= remain;
            root->cnt += remain;
            root->todo = true;
            return;
        }
        root->push();
        update(root->right, L, R);
        update(root->left, L, R);
        root->pull();
    }

    int findMinimumTime(vector<vector<int>>& tasks) {
        // goal: find the minimum time to finish all tasks
        // idea:
        // segment tree

        // sort by end
        sort(tasks.begin(), tasks.end(), [&](auto &a, auto &b){
            return a[1] < b[1];
        });

        node* root = new node(1, 2001);
        for (auto &t: tasks) {
            int l = t[0], r = t[1], d = t[2];
            suffix = d - query(root, l, r);
            if (suffix > 0) update(root, l, r);
        }

        return root->cnt;
    }
};
