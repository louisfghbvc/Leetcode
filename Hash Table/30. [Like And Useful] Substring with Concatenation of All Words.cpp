// two map. O(NKL). k = word.size(), l = word[0].size()
// for each index try to map string length
// like brute-force search. search all string in word use map
// ignore permutation use map.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto &w: words) mp[w]++;
        int n = s.size(), num = words.size();
        vector<int> res;
        if(!n || !num) return res;
        int len = words[0].size();
        for(int i = 0; i <= n - num * len; ++i){
            unordered_map<string, int> seen;
            int j = 0;
            for(; j < num; ++j){
                string w = s.substr(i + j*len, len);
                if(mp.count(w)){
                    if(++seen[w] > mp[w]) break;
                }
                else break;
            }
            if(j == num) res.push_back(i);
        }
        return res;
    }
};
