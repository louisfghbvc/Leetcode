// Simple, just split string into array. and prefix use ==
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        vector<string> v;
        string t;
        while(ss >> t) v.push_back(t);
        int l = searchWord.size();
        for(int i = 0; i < v.size(); ++i){
            if(v[i].substr(0, l) == searchWord) return i+1;
        }
        return -1;
    }
};
