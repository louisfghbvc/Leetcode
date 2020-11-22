// too simple. concate and compare.
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "", b = "";
        for(auto&s: word1) a+=s;
        for(auto&s: word2) b+=s;
        return a == b;
    }
};
