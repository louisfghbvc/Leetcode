# [2276. Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals/)

###### tags: `leetcode` `hard` `odt`

[TOC]

## Description
Add the interval [l, r]
Count the nubmer of integers that are already set

## Way1 - ODT

```c++
class CountIntervals {
    
public:
    struct node{
        int l;
        mutable int r;
        bool exist = true;
        bool operator<(const node& n2) const {
            return l < n2.l;
        }
    };
    
    auto split(int x) { // [l, r] -> [l, x-1], [x, r]
        auto it = prev(odt.upper_bound({x}));
        if (it->l == x) return it;
        node tmp = *it;
        it->r = x-1;
        tmp.l = x;
        return odt.insert(tmp).first;
    }
    
    CountIntervals() {
        odt.insert({1, (int)1e9});
    }
    
    void add(int left, int right) {
        auto itl = split(left);
        auto itr = split(right+1);
        for (auto it = itl; it != itr; it = odt.erase(it)) {
            if (it->exist)
                ans += it->r - it->l + 1;
        }
        odt.insert({left, right, 0});
    }
    
    int count() {
        return ans;
    }
    
private:
    set<node> odt;
    int ans = 0;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
```

## Way2 - Segment tree
```c++
class CountIntervals {
    struct node {
        node *l, *r;
        int cnt, s, e; // sum of the range, start, end
        node (int s, int e) : s(s), e(e), cnt(0) {
            l = r = nullptr;
        }
        node* getL() {
            if (!l) l = new node(s, (s+e)/2);
            return l;
        }
        node* getR() {
            if (!r) r = new node((s+e)/2+1, e);
            return r;
        }
    };
    
    void update(node* r, int s, int e) { // [root, start, end]
        if (r->s > e || r->e < s) return;
        if (s <= r->s && r->e <= e) { 
            r->cnt = r->e-r->s+1;
            return;
        }
        int mid = (r->s+r->e)/2;
        update(r->getL(), s, e);
        update(r->getR(), s, e);
        r->cnt = max(r->cnt, r->getL()->cnt + r->getR()->cnt);
    }
    
public:
    CountIntervals() {
        root = new node(1, 1e9);
    }
    
    // add [left, right]
    void add(int left, int right) {
        update(root, left, right);
    }
    
    // count the all interval ranges
    int count() {
        return root->cnt;
    }
    
private:
    node *root;
};
```
## Complexity

| complexity | time | space |
| - | - | - |
| Way1 | O(logn) | O(n) |
| Way2 | O(logn) | O(n) |

