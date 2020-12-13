// very simple. O(NM).

class Solution {
public:
    int countConsistentStrings(string a, vector<string>& words) {
        int cnt = 0;
        unordered_set<char> st(a.begin(), a.end());
        for(auto &c: words){
            bool ok = true;
            for(char cc: c){
                if(!st.count(cc)) ok = false;
            }
            cnt +=ok;
        }
        return cnt;
    }
};
