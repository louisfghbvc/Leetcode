//16ms 11.1MB
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
        vector<int> mp(words.size());
        for(int i = 0; i < words.size(); ++i){
            int fre[26] = {};
            for(int j = 0; j < words[i].size(); ++j){
                fre[words[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; ++j){
                if(fre[j] > 0){
                    mp[i] = fre[j]; break;
                }
            }
        }
        sort(mp.begin(), mp.end());
        for(auto s : queries){
            int fre[26] = {};
            int f = 0, cnt = 0;
            for(int i = 0; i < s.size(); ++i)
                fre[s[i] - 'a']++;
            for(int j = 0; j < 26; ++j){
                if(fre[j] > 0){
                    f = fre[j]; break;
                }
            }
            ans.push_back(mp.size() - (upper_bound(mp.begin(), mp.end(), f) - mp.begin()));
        }
        return ans;
    }
};
