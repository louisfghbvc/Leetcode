class Solution {
public:
    bool checkRecord(string s) {
        int fre[26] = {};
        for(int i = 0; i < s.size(); ++i){
            fre[s[i] - 'A']++;
            if(s[i] != 'L')
                fre['L' - 'A'] = 0;
            if(fre[0] > 1) 
                return false;
            if(fre['L' - 'A'] > 2) 
                return false;
        }
        return true;
    }
};
