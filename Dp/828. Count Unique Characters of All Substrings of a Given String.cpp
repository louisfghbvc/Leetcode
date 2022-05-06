class Solution {
public:
    int uniqueLetterString(string s) {
        // countUniqueChars(s): the distinct chars
        // goal: calculate all substring function
        // idea: calculate each chars contribution
        // use index to record the chars
        
        
        vector<int> prev(26, -1);
        vector<queue<int>> idx(26);
        
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            idx[s[i]-'A'].push(i);
        }
                
        int res = 0;
        for (int i = 0; i < n; ++i) {
            idx[s[i]-'A'].pop();
            int left = i - prev[s[i]-'A'];
            int right;
            if (idx[s[i]-'A'].size()) { // have next
                right = idx[s[i]-'A'].front() - i;
            }
            else {
                right = n - i;
            }
            res += left * right;
            prev[s[i]-'A'] = i;
        }
        
        return res;
    }
};
