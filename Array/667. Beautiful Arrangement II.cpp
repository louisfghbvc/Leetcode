// O(N). Find the rule to fast build array. just do it

class Solution {
public:
    // 5
    // 1 2 3 4 5   1
    // 1 2 3 5 4   2
    // 1 2 5 3 4   3
    // 1 5 2 4 3   4
    
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        for(int i = 0; i < n - k; ++i)
            res[i] = i+1;
        int cur = res[n - 1 - k];
        bool up = 1;
        for(int i = n - k, diff = k; i < n; ++i, diff--){
            if(up) res[i] = res[i-1] + diff;
            else res[i] = res[i-1] - diff;
            up ^= 1;
        }
        return res;
    }
};
