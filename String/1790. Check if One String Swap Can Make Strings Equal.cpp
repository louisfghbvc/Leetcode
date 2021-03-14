// Simple O(N). Careful the case... WA 4times -0-

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int cnt = 0;
        vector<int> id;
        for(int i = 0; i < n; ++i){
            cnt += s1[i] != s2[i];
            if(s1[i] != s2[i]) id.push_back(i);
        }
        if(cnt == 2){
            if(s1[id[0]] == s2[id[1]] && s1[id[1]] == s2[id[0]]) return true;
            else return false;
        }
        return cnt == 0;
    }
};
