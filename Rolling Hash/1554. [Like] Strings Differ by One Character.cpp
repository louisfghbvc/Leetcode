// O(NM), use rolling hash, and unsigned long long tricky!

class Solution {
public:
    
    typedef unsigned long long ull;
    bool differByOne(vector<string>& dict) {
        int n = dict.size(), m = dict[0].size();
        
        vector<ull> hashes;
        for(auto &s: dict){
            ull val = 0;
            for(int i = 0; i < m; ++i){
                val = val * 26 + (s[i] - 'a');
            }
            hashes.push_back(val);
        }
        
        ull base = 1;
        for(int j = m-1; j >= 0; --j){
            unordered_set<ull> st;
            for(int i = 0; i < n; ++i){
                ull tmp = hashes[i] - (dict[i][j] - 'a') * base;
                if(!st.insert(tmp).second) return true;
            }
            base *= 26;
        }
        
        return false;
    }
};


// use just set
// O(NM)?

class Solution {
public:
    
    bool differByOne(vector<string>& dict) {
        for(int i = 0; i < dict[0].size(); ++i){
            unordered_set<string> st;
            for(auto &s: dict){
                char tmp = s[i];
                s[i] = '{';
                if(!st.insert(s).second) return true;
                s[i] = tmp;
            }   
        }
        return false;
    }
};
