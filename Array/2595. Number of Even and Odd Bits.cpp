class Solution {
public:
    
    string bin(int x) {
        string res;
        while (x) {
            res.push_back('0' + x%2);
            x >>= 1;
        }
        return res;
    }
    
    vector<int> evenOddBit(int n) {
        string res = bin(n);
        vector<int> ans(2);
        for (int i = 0; i < res.size(); ++i)
            ans[i % 2] += res[i] == '1';
        return ans;
    }
};
