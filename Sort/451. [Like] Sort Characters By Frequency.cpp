// Counting sort.
// record max.

class Solution {
public:
    string frequencySort(string s) {
        int fre[128] = {};
        int mx = 0;
        for(const auto &c: s) fre[c]++, mx = max(mx, fre[c]);
        string res = "";
        for(int l = mx; l >= 1; --l){
            for(int i = 0; i < 128; ++i){
                if(fre[i] == l){
                    res += string(fre[i], char(i));  fre[i] = 0;
                }
            }
        }
        return res;
    }
};
