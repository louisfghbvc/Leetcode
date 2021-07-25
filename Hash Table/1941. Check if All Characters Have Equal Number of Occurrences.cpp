class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> mp;
        for(char c: s) mp[c]++;
        int prev = -1;
        for(auto [_, v]: mp){
            if(prev != -1){
                if(prev != v) return false;
            }
            prev = v;
        }
        return true;
    }
};
