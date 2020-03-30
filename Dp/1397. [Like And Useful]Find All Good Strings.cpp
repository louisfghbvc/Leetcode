//96ms 18.5MB
//Kmp is amazing. Top-down. useS1, useS2 is boundary. leftmost, rightmost.
class Solution {
private:
    const int mod = 1e9+7;
public:
    vector<int> lps(const string &s){
        vector<int> res(s.size(), 0);
        for(int i = 0, j = 1; j < s.size(); ++j){
            while(i > 0 && s[i] != s[j]) i = res[i - 1];
            if(s[i] == s[j]) res[j] = ++i;
        }   
        return res;
    }
    
    int dfs(int i, int j, bool useS1, bool useS2, const string &s1, const string &s2, const int n, const string &evil, const vector<int> &v, 
    vector<vector<vector<vector<int>>>> &memo){
        if(j == evil.size()) return 0;
        if(i == n) return 1;
        if(memo[i][j][useS1][useS2] != -1) return memo[i][j][useS1][useS2];
        
        char from = useS1 ? s1[i] : 'a';
        char to = useS2 ? s2[i] : 'z';
        
        int res = 0;
        for(char c = from; c <= to; ++c){
            int nextMatch = j;
            while(nextMatch > 0 && c != evil[nextMatch]) nextMatch = v[nextMatch-1];
            if(c == evil[nextMatch]) nextMatch++;
            
            res += dfs(i+1, nextMatch, useS1 && c == from, useS2 && c == to,
                      s1, s2, n, evil, v, memo);
            
            res %= mod;
            
        }
        
        return memo[i][j][useS1][useS2] = res;
    }
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<vector<vector<vector<int>>>> memo = vector(n + 1, vector(evil.size()+1, vector(2, vector<int>(2, -1))));
        
        return dfs(0, 0, true, true, s1, s2, n, evil, lps(evil), memo);
    }
    
};
