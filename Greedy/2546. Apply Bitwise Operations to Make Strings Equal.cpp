class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        // goal: find if can change s to target
        // idea: 
        // operation1: s[i], s[j], i!=j, s[i] = s[i] or s[j], s[j] = s[i] ^ s[j]
        
        // 1, 1 -> 1, 0
        // 1, 0 -> 1, 1
        // 0, 1 -> 1, 1
        
        // 0 and 1 can swap -> no need the order
        
        // 1 1 1, 1 1 0
        // 1 1 0, -> 1 0 0
                    
        int n = s.size();
        int cnt = count(target.begin(), target.end(), '0');
        if (cnt == n)
            return count(s.begin(), s.end(), '0') == n;
        
        return count(s.begin(), s.end(), '0') != n;
    }
};
