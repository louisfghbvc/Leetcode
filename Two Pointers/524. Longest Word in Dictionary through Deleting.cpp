// Simple compare. and sort.
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<pair<int, string>> arr;
        for(auto &r: d){
            int i = 0, j = 0;
            while(i < s.size() && j < r.size()){
                if(s[i] == r[j]) j++;
                i++;
            }
            if(j == r.size()) arr.push_back({r.size(), r});
        }
        sort(arr.begin(), arr.end(), [&](auto &a, auto& b){
            return a.first > b.first || (a.first == b.first && a < b);
        });
        if(arr.empty()) return "";
        return arr.begin()->second;
    }
};

// No need to sort, just compare.
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(auto &r: d){
            int i = 0, j = 0;
            while(i < s.size() && j < r.size()){
                if(s[i] == r[j]) j++;
                i++;
            }
            if(j == r.size()){
                if(r.size() > res.size() || r.size() == res.size() && res > r) res = r; 
            }
        }
        return res;
    }
};
