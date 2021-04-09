// O(NM). M is compare. so just mapping and compare adjacent.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26] = {};
        for(int i = 0; i < 26; ++i)
            mapping[order[i] - 'a'] = i;

        auto cmp = [&](auto &a, auto &b){
            int i = 0, j = 0;
            while(i < a.size() && j < b.size()){
                if(mapping[a[i] - 'a'] != mapping[b[j] - 'a'])
                    return mapping[a[i] - 'a'] < mapping[b[j] - 'a'];
                i++, j++;
            }
            if(i == a.size()) return true;
            if(j == b.size()) return false;
            return true;
        };
        
        for(int i = 1; i < words.size(); ++i){
            if(!cmp(words[i-1], words[i])) return false;
        }
        
        return true;
    }
};
