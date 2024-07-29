// really hard to think out clean version code
// fix the left, enumerate zero number
// when we have 1 zero
// e.g 1 1 0 1 1 1 1 0
//         i         j
// we have j - i ending r
// but we also need to compute zero^2 < one
// if one too small need to move i to right : i = i+zero^2-one

class Solution {
public:
    int numberOfSubstrings(string s) {
        // goal: find the number of substring such that one > zero^2
        // idea:
        // fix the left point, we are enumerate zero number
        
        //       i      j
        // ... 1101011110
        // cnt 0: a[j] - a[j-1]
        // cnt 1: a[j] - a[j-1] - need

        int n = s.size();
        vector<int> pos0;
        for (int i = 0; i < n; ++i)
            if (s[i] == '0')
                pos0.push_back(i);
        int tot1 = n - pos0.size();

        // add dummy 0, 0111
        pos0.push_back(n);

        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            // enumerate zero number
            for (int k = j; k+1 < pos0.size(); ++k) {
                int zero = k-j+1;
                if (zero * zero > tot1) break;
                
                // len = [i, pos0[k]]
                int one = (pos0[k]-i+1) - zero;
                if (one > zero*zero) {
                    ans += pos0[k+1] - pos0[k];
                }
                else { // need = zero^2 - one
                    int need = zero*zero - one;
                    ans += max(0, pos0[k+1] - (pos0[k]+need) );
                }
            }

            if (s[i] == '0') j++;
            else { // no zero case
                ans += pos0[j] - i;
            }
        }

        return ans;
    }
};
