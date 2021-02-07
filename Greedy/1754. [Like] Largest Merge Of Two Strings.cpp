// O(MN). debug long time ==.
class Solution {
public:
    bool big(string &a, string &b, int i, int j){
        while(i < a.size() && j < b.size() && a[i] == b[j]){
            i++, j++;
        }
        char g = (i == a.size()) ? 0 : a[i];
        char g2 = (j == b.size()) ? 0 : b[j];
        return g > g2;
    }
    string largestMerge(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        string res = "";
        int l = 0, r = 0;
        while(l < n && r < m){
            if(big(w1, w2, l, r)) res += w1[l++];
            else res += w2[r++];
        }
        while(l < n) res += w1[l++];
        while(r < m) res += w2[r++];
        return res;
    }
};
