// weird problem. random num but has probability.
// O(nlogn)
// use upper bound to binary search

class Solution {
public:
    vector<int> vh;
    int h;
    Solution(vector<int>& w) {
        h = 0;
        vh = w;
        for(int i = 0; i < w.size(); ++i){
            vh[i] = h;
            h += w[i];
        }
    }
    
    int pickIndex() {
        int r = rand() % h;
        return upper_bound(vh.begin(), vh.end(), r) - vh.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
