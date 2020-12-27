// Very simple. O(N).

class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> vol = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int n = s.size()/2;
        int c1 = 0, c2 = 0;
        for(int i = 0, j = n; i < n; i++, ++j){
            c1 += vol.count(s[i]);
            c2 += vol.count(s[j]);
        }
        return c1 == c2;        
    }
};
