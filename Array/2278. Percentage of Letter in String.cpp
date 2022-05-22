class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        int cnt = count(s.begin(), s.end(), letter);
        return 1.0 * cnt / n * 100;
    }
};
