// O(N^3). bf.
class Solution {
public:
    int maxRepeating(string s, string word) {
        int res = 0;
        for(int i = 0; i+word.size()-1 < s.size(); ++i){
            int tmp = 0, j = i;
            while(j+word.size()-1 < s.size() && s.substr(j, word.size()) == word) tmp++, j+=word.size();
            res = max(res, tmp);
        }
        return res;
    }
};

// Cool c++ string find.
class Solution {
public:
    int maxRepeating(string s, string word) {
        int res = 0;
        string tmp = word;
        while(s.find(tmp) != -1){
            res++;
            tmp += word;
        }
        return res;
    }
};
