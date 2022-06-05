class RangeModule {
    
public:
    struct node {
        int l;
        mutable int r;
        bool exist;
        bool operator< (const node& n2) const {
            return l < n2.l;
        }
    };
    
    auto split(int x) { // [l, r] -> [l, x-1] [x, r]
        auto it = prev(odt.upper_bound({x}));
        if (it->l == x) return it;
        node tmp = *it;
        it->r = x-1;
        tmp.l = x;
        return odt.insert(tmp).first;
    }
    
    RangeModule() {
        odt.insert({1, (long)1e9, 0});
    }
    
    void addRange(int left, int right) {
        auto itl = split(left);
        auto itr = split(right);
        odt.erase(itl, itr);
        odt.insert({left, right-1, 1});
    }
    
    bool queryRange(int left, int right) {
        auto itl = split(left);
        auto itr = split(right);
        int seg = 0;
        for (auto it = itl; it != itr; ++it)
            if (it->exist)
                seg += it->r - it->l + 1;
        return seg == right - left;
    }
    
    void removeRange(int left, int right) {
        auto itl = split(left);
        auto itr = split(right);
        odt.erase(itl, itr);
        odt.insert({left, right-1, 0});
    }

private:
    set<node> odt;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
