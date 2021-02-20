// Simple but slow. O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> fre(52);
        vector<int> fre2(52);
        
        for(char c: t){
            if(isupper(c))
                fre[c - 'A' + 26]++;
            else 
                fre[c - 'a']++;
        }
        
        auto checkSame = [&](){
            for(int i = 0; i < 52; ++i){
                if(fre2[i] < fre[i]) return false;
            }
            return true;
        };
        
        int ansl = 0, ansr = s.size()+1;
        for(int r = 0, l = 0; r < s.size(); ++r){
            char c = s[r];
            if(isupper(c))
                fre2[c - 'A' + 26]++;
            else 
                fre2[c - 'a']++;
            while(checkSame()){
                if(r-l+1 < ansr-ansl+1){
                    ansl = l;
                    ansr = r;
                }
                c = s[l++];
                if(isupper(c))
                    fre2[c - 'A' + 26]--;
                else 
                    fre2[c - 'a']--;
            }
        }
        
        if(ansr - ansl + 1 > s.size()) return "";
        return s.substr(ansl, ansr - ansl + 1);
    }
};

// Optimize use size. O(N).
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128);
        int tdiff = 0;
        for(char c: t){
            if(need[c] == 0) tdiff++;
            need[c]++;
        }
        
        int ansl = 0, ansr = s.size()+1;
        vector<int> cur(128);
        int sdiff = 0;
        for(int r = 0, l = 0; r < s.size(); ++r){
            cur[s[r]]++;
            if(cur[s[r]] == need[s[r]]) sdiff++;
            while(sdiff == tdiff){
                if(r-l+1 < ansr-ansl+1){
                    ansl = l;
                    ansr = r;
                }
                char c = s[l++];
                cur[c]--;
                if(cur[c] < need[c]) --sdiff;
            }
        }
        
        if(ansr - ansl + 1 > s.size()) return "";
        return s.substr(ansl, ansr - ansl + 1);
    }
};
