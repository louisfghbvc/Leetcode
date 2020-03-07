//4ms 8.9MB Sort
class Solution {
public:
    string sortString(string s) {
        string res = "";
        int fre[26] = {};
        for(int i = 0; i < s.size(); ++i)
            fre[s[i] - 'a']++;
        int cnt = 0;
        while(res.size() < s.size()){
            for(int i = 0; i < 26; ++i){
                if(fre[i] > 0){
                    res += ('a' + i);
                    fre[i]--;
                }
            }
            for(int i = 25; i >= 0; --i){
                if(fre[i] > 0){
                    res += ('a' + i);
                    fre[i]--;
                }
            }
        }
        return res;
    }
};
