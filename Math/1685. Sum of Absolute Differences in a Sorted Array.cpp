// Can O(1) space. use suf = tot - pre.
// O(N)
// so many duplicate so use prefix and suffix.

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        vector<int> suf(n);
        suf[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i) suf[i] += suf[i+1] + arr[i];
        
        long pre = 0;
        for(int i = 0; i < n; ++i){
            long big = n-1-i;
            res.push_back((long)i*arr[i] - pre + suf[i] - big*arr[i] - arr[i]);
            pre += arr[i];
        }
        
        return res;
    }
};
