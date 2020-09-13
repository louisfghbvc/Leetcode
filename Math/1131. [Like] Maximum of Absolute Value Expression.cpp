// abs magic. |A|+|B| = max(|A+B|, |A-B|) lemma1.
// apply more width
// |A|+|B|+|C| => max(|A+B+C|, |A+B+C|, |A-B+C|, |A-B-C|).
// and j is monotonous. because max abs val say |x| = mx-mn. O(N).
// O(N).

class Solution {
public:
    int MaxAbs(vector<int> &arr){
        int mx = -1e6, mn = 1e6;
        for(int x: arr){
            mx = max(mx, x);
            mn = min(mn, x);
        }    
        return mx - mn;
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<vector<int>> pattern(4, vector<int>(n));
        for(int i = 0; i < n; ++i){
            pattern[0][i] = arr1[i] + arr2[i] + i;
            pattern[1][i] = arr1[i] + arr2[i] - i;
            pattern[2][i] = arr1[i] - arr2[i] + i;
            pattern[3][i] = arr1[i] - arr2[i] - i;
        }
        return max({MaxAbs(pattern[0]), MaxAbs(pattern[1]), MaxAbs(pattern[2]), MaxAbs(pattern[3])});
    }
};
