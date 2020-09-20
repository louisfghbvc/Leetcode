// just BruteForce. but I stick with the cut to 2 string.
// autcually just cut left. and other go to recursive, same as cut 2.
// still noob. sad.

class Solution {
public:
    int mx;
    int n;
    void dfs(int pos, string &s, unordered_set<string> &st){
        if(pos == n){
            mx = max((int)st.size(), mx);
            return;
        }
        string cur = "";
        for(int i = pos; i < n; ++i){
            cur += s[i];
            if(!st.count(cur)){
                st.insert(cur);
                dfs(i+1, s, st);
                st.erase(cur);
            }
        }
    }
    int maxUniqueSplit(string s) {
        n = s.size();
        unordered_set<string> st;
        dfs(0, s, st);
        return mx;
    }
};
