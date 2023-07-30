class Solution {
public:
    
    bool lcs(string &a, string &b) {
        if (a.size() < b.size()) return false;
        for (int i = 0; i < a.size(); ++i) {
            int j;
            for (j = 0; j < b.size(); ++j) {
                if (a[i+j] != b[j]) break;
            }
            if (j == b.size()) return true;
        }
        return false;
    }
    
    string minimumString(string a, string b, string c) {
        // goal: find the smallest string contains a,b,c substring
        
        // 1 <= a,b,c size <= 100
        // a,b,c's char is lowercase letter
        
        // aabbcc, ans=6
        
        // aab,abc,aa, ans=4
        // aabc
        // may overlapping in each string
        
        // aba, ac
        // abac
        
        // bab,abc,aa, ans=6
        // aababc
        
        
        
        // idea:
        // a,b,c -> each combination
        // find the longest commom suffix cur, prefix of the string match
        // update the ans
        
        // bab,abc,aa, ans=4
        // aa -> abc -> bab -> aabcbab
        // aa -> bab -> abc -> aababc
        // bab -> aa -> abc -> babaabc
        
        // TC: O(6 * n^2)
        
        vector<string> arr = {a, b, c};
        sort(arr.begin(), arr.end());
        
        string ans;
        do {

            string s = arr[0];
            for (int i = 1; i < 3; ++i) {
                string t = arr[i];
                
                // find s'suffix and t's prefix match
                int len = min(s.size(), t.size());
                string pre, suf;
                int match = 0;
                for (int j = 0; j < len; ++j) {
                    pre += t[j];
                    suf.insert(suf.begin(), s[(int)s.size()-j-1]);
                    if (pre == suf) match = j+1;
                }
                
                // s not full match t
                if (!lcs(s, t))
                    s += t.substr(match); 
            }
            
            if (ans.empty() || ans.size() > s.size() || ans.size() == s.size() && ans > s)
                ans = s;
        } while (next_permutation(arr.begin(), arr.end()));
        
        return ans;
    }
};

// can use rolling hash to improve pre suf match
