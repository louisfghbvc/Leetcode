class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int n = num1.size();
        int m = num2.size();
        
        vector<int> res(n+m);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                res[i+j] += (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] += res[i+j] / 10;
                res[i+j] %= 10;
            }
        }
        
        // leading zero
        while(res.size() > 1 && res.back() == 0) res.pop_back();

        reverse(res.begin(), res.end());
        
        string ans = "";
        for(int x: res) ans += '0' + x;
        
        return ans;
    }
};
