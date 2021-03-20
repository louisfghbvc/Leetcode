// lol clean...

class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        for(char c: s){
            if(isdigit(c)) st.insert(c-'0');
        }
        
        return st.size() > 1 ? *prev(st.end(), 2) : -1;
    }
};

// use two param.

class Solution {
public:
    int secondHighest(string s) {
        int cnt[10] = {};
        for(char c: s){
            if(isdigit(c)) cnt[c-'0']++;
        }
        
        int m1 = -1, m2 = -1;
        for(int i = 9; i >= 0; --i){
            if(cnt[i]){
                if(i > m1){
                    m2 = m1;
                    m1 = i;
                }
                else if(i > m2){
                    m2 = i;
                }
            }
        }
        
        return m2;
    }
};
