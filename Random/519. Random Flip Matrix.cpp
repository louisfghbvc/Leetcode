// use set to record occur.

class Solution {
public:
    int r, c;
    unordered_set<int> st;
    Solution(int n_rows, int n_cols) {
        r = n_rows;
        c = n_cols;
    }
    
    vector<int> flip() {
        if(st.size() == r*c) return {};
        int x = rand() % (r*c);
        while(st.count(x)){
            x = (++x)%(r*c);
        }
        st.insert(x);
        return {x/c, x%c};
    }
    
    void reset() {
        st = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
