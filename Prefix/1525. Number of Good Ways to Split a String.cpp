// use prefix and suffix, easy calculate. clean.
// O(N). 76ms
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> pre(n), suf(n);
        unordered_set<char> st;
        for(int i = 0; i < n; ++i){
            st.insert(s[i]);
            pre[i] = st.size();
        }
        st.clear();
        for(int i = n-1; i >= 0; --i){
            st.insert(s[i]);
            suf[i] = st.size();
        }
        int ans = 0;
        for(int i = 0; i < n - 1; ++i){
            if(pre[i] == suf[i+1]) ans++;
        }
        return ans;
    }
};

// O(26*N). More bruteforce
// 232ms
class Solution {
public:
    int numSplits(string s) {
        vector<int> fre(26);
        for(auto c: s) fre[c-'a']++;
        int ans = 0;
        vector<int> tmp(26);
        for(int i = 0; i < s.size(); ++i){
            tmp[s[i]-'a']++;
            vector<int> com(26);
            for(int j = 0; j < 26; ++j) com[j] = fre[j] - tmp[j];
            int c1 = 0, c2 = 0;
            for(int j = 0; j < 26; ++j){
                if(tmp[j]) c1++;
                if(com[j]) c2++;
            }
            ans += (c1 == c2);
        }
        return ans;
    }
};
