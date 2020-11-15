// operation1: can get a sorted string.
// operation2: can get a sorted fre.
// O(N).

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt1(26), cnt2(26);
        for(char c: word1) cnt1[c-'a']++;
        for(char c: word2) cnt2[c-'a']++;
        if(cnt1 == cnt2) return true;
        bool tar = 1;
        for(int i = 0; i < 26; ++i){
            if(!cnt1[i] && cnt2[i]) tar = 0;
            else if(cnt1[i] && !cnt2[i]) tar = 0;
        }
        if(tar){
            sort(cnt1.begin(), cnt1.end());
            sort(cnt2.begin(), cnt2.end());
            if(cnt1 == cnt2) return true;
        }
        return false;
    }
};
