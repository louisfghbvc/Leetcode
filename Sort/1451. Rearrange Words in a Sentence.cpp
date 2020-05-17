// use stringstream or strtok (c.lib)
#include <bits/stdc++.h>
class Solution {
public:
    struct node{
        int len, id;  
        string s;
        bool operator<(const node n2) const {
            return len < n2.len || (len == n2.len && id < n2.id);
        }
    };
    string arrangeWords(string text) {
        stringstream ss(text);
        string str;
        vector<node> v;
        int id = 0;
        while(ss >> str){
            v.push_back({(int)str.size(), id++, str});            
        }
        sort(v.begin(), v.end());
        string ans = v[0].s;
        ans[0] = toupper(ans[0]);
        for(int i = 1; i < v.size(); ++i){
            v[i].s[0] = tolower(v[i].s[0]);
            ans += " " + v[i].s;
        }
        return ans;
    }
};
