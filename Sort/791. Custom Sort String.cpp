class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> mp(26, -1);
        for(int i = 0; i < order.size(); ++i) mp[order[i] - 'a'] = i;
        sort(str.begin(), str.end(), [&](char a, char b){
            return mp[a-'a'] < mp[b-'a'];
        });
        return str;
    }
};
