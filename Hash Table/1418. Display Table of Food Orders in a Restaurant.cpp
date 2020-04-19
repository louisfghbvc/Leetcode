//use stoi can string to int.
//use map to solve.
class Solution {
public:
    int toi(string &s){
        int ans = 0;
        for(int i= 0; i < s.size(); ++i){
            ans = ans*10 + (s[i]-'0');
        }
        return ans;
    }
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans;
        unordered_map<string, int> mp;
        set<string> st;
        set<int> table;
        for(auto &o : orders){
            mp[o[1]+o[2]]++;
            st.insert(o[2]);
            table.insert(toi(o[1]));
        }
        vector<string> t = {"Table"};
        for(auto &s: st){
            t.push_back(s);
        }
        ans.push_back(t);
        for(auto &ta: table){
            vector<string> tt;
            for(int i = 0; i < t.size(); ++i){
                if(i == 0) tt.push_back(to_string(ta));
                else{
                    tt.push_back(to_string(mp[to_string(ta)+t[i]]));
                }
            }
            ans.push_back(tt);
        }
        
        return ans;
    }
};
