class Solution {
public:
    
    bool isP(string &s) {
        string t(s.rbegin(), s.rend());
        return s == t;
    }
    
    bool isStrictlyPalindromic(int n) {
        // goal: for each base in [2,n-2] is palindromic
        // idea: try to simulate it
        
        // TC: O(NlogN)
        
        for (int b = 2; b <= n-2; ++b) {
            string s;
            int val = n;
            while (val) {
                s.push_back('0'+val%b);
                val /= b;
            }
            if (!isP(s)) return false; // O(logN)
        }
        
        return true;
    }
};


// n-2 always false

