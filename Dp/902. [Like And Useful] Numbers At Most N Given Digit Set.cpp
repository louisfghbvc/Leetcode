// Digit dp + math
// so first sum < length n possible.
// and from leftmost to right.
// compute. and if can not have same digit. no need to compute remain.

// e.g. 100. digits = {1, 3, 5}.
// so first compute. xx + x. 3^2 + 3^1
// and fix 1xx. and has same but no need to add.
// 10x. no and return.

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string N = to_string(n);
        int ds = digits.size(), ns = N.size();
        
        int res = 0;
        for(int i = 1; i < ns; ++i)
            res += pow(ds, i);
        
        for(int i = 0; i < ns; ++i){
            bool same = false;
            for(string &sd: digits){
                if(sd[0] < N[i])
                    res += pow(ds, ns - 1 - i);
                else if(sd[0] == N[i]) same = true;
            }
            if(!same) return res;
        }
        
        return res+1;
    }
};
