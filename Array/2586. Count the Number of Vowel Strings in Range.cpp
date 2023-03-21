class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        
        string s = "aeiou";
        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            if (s.find(words[i][0]) != -1 && s.find(words[i].back()) != -1)
               cnt++;
        }
        return cnt;
    }
};
