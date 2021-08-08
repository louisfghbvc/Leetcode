// O(N^2). BF. can improve to O(N).
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string tmp = "";
        for(int j = 0; j < words.size(); ++j){
            tmp += words[j];
            if(tmp == s) return true;
        }
        return false;
    }
};
