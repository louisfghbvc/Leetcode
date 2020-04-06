//map version 76ms 16.9MB. cool array index
class Solution {
public:
    array<char, 26> getkey(string &s){
        array<char, 26> arr{};
        for(const auto &ch : s)
            arr[ch-'a']++;
        return arr;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<char, 26>, vector<string>> mp;
        for(auto &s: strs){
            mp[getkey(s)].push_back(move(s));
        }
        vector<vector<string>> ans;
        for(const auto &x: mp){
            ans.push_back(move(x.second));
        }
        return ans;
    }
};

//unordered_map version 64ms 16.9MB, move is fast a lot
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(const auto &s: strs){
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(const auto &x: mp){
            ans.push_back(move(x.second));
        }
        return ans;
    }
};
