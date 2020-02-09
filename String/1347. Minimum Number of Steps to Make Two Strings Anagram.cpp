class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {}, count2[26] = {};
        for(auto c : s)
            count[c - 'a']++;
        for(auto c : t)
            count2[c - 'a']++;
        int res = 0;
        for(int i = 0; i < 26; ++i){
            if(count[i] > count2[i]){
                res += count[i] - count2[i];
            }
        }
        return res;
    }
};
