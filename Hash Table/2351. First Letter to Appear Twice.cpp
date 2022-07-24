class Solution {
public:
    char repeatedCharacter(string s) {
        // goal: find the first repeat letter
        
        unordered_map<char, int> mp;
        for (char c: s) {
            mp[c]++;
            if (mp[c] > 1) return c;
        }
        
        return '0';
    }
};
