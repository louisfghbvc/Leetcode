class Solution {
public:
    int countAsterisks(string s) {
        
        int cnt = 0;
        int include_star = 0;
        for (char c: s) {
            cnt += (c == '|');
            if (cnt % 2)
                include_star += c == '*';
        }
        
        return count(s.begin(), s.end(), '*') - include_star;
    }
};
