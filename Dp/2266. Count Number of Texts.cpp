class Solution {
public:
    
    int dfs(int i) { // n distinct index
        if (i == n) return 1;
        
        int &res = dp[i];
        if (res != -1) return res;
        res = 0;
        
        int d = s[i]-'0'; // 2
        int lengthMax = digitCnt[d];
        
        // at most 4
        for (int j = 0; j < lengthMax; ++j) { // dp[i] += dp[i+j+1] 
            if (i+j < n && s[i+j]-'0' == d) { // continous digit
                res = (res + dfs(i+j+1)) % mod;
            }
            else break;
        }
        
        return res;
    }
    
    int countTexts(string pressedKeys) {
        // goal: calculate the number of distinct string can be builded
        // idea: dp[i] number of ways so far
        // dp[i] -> calculate the length that can have, move to dp[i+len], length maximum is digitCnt
        
        // preprocessing the length of each digit
        for (int i = 1; i <= 6; ++i)
            digitCnt[i] = 3; 
        digitCnt[7] = digitCnt[9] = 4;
        digitCnt[8] = 3; 
        
        n = pressedKeys.size();
        s = pressedKeys;
        dp = vector<int>(n, -1);
        
        return dfs(0);
    }
    
private:
    const int mod = 1e9+7;
    vector<int> dp;
    int n;
    string s;
    unordered_map<int, int> digitCnt; // number -> that can press
};
