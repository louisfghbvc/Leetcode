// Simple O(N). just maintain a increasing order string.

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int res = 0;
        unordered_map<char, int> fre;
        
        string s = "";
        for(int r = 0; r < word.size(); ++r){
            while(s.size() && word[r] < s.back()){
                fre.clear();
                s.clear();
            }
            s.push_back(word[r]);
            fre[word[r]]++;
            if(fre.size() == 5){
                res = max(res, (int)s.size());
            }
        }
        
        return res;
    }
};
