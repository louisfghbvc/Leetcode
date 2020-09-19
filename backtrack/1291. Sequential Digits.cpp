// Simple iterative. O(1). generate all number. 12. 123. 1234.. 123456789. 2. 23. 234..
// super clean.

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int d = 1; d <= 9; ++d){
            int val = 0;
            for(int d2 = d; d2 <= 9; ++d2){
                val = val * 10 + d2;
                if(val >= low && val <= high){
                    res.push_back(val);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};


// Recursive.
class Solution {
public:
    void gen(vector<int> &res, int dl, int i = 0, int l = 0, int val = 0){
        if(l == dl){
            res.push_back(val);
            return;
        }
        if(i+1 > 9) return;
        gen(res, dl, i+1, l+1, val*10+i+1);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> gan;
        for(int l = 2; l <= 10; ++l)
            for(int i = 0; i <= 9; ++i)
                gen(gan, l, i);
        
        vector<int> res;
        for(int x: gan)
            if(x >= low && x <= high) res.push_back(x);
        
        return res;
    }
};
