// careful the cycle, since cycle always fail!
// otherwise just convert str1 -> str2, can be many to one
// O(N).

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        
        // convert str1 to str2
        // if char is not equal or equal must convert
        
        vector<char> mapping(26, 0);
        set<char> cnt; // can not be 26
        for(int i = 0; i < str1.size(); ++i){
            if(mapping[str1[i] - 'a'] == 0) mapping[str1[i]-'a'] = str2[i];
            if(mapping[str1[i] - 'a'] != str2[i]) return false;
            cnt.insert(mapping[str1[i]-'a']);
        }
        
        return cnt.size() != 26;
    }
};
