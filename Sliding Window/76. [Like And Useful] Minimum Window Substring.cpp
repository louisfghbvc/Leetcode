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

// Optimize just compare size. O(N).
class Solution {
public:
    
    int conv(char c){
        return isupper(c) ? 26 + c-'A' : c-'a';
    }
    
    string minWindow(string s, string t) {
        int m = s.size();
        
        vector<int> fre(52);
        int cnt = 0;
        for(char c: t){
            if(fre[conv(c)]++ == 0) cnt++;
        }
        
        int res = 1e9, ans_l = 1e9, ans_r = 0;
        for(int r = 0, l = 0; r < m; ++r){
            if(--fre[conv(s[r])] == 0) cnt--;
            while(cnt == 0){
                if(res > r-l+1){
                    res = r-l+1;
                    ans_l = l, ans_r = r;
                }
                if(fre[conv(s[l])]++ == 0) cnt++;
                l++;
            }
        }
        
        if(ans_l > ans_r) return "";
        return s.substr(ans_l, ans_r - ans_l+1);
    }
};
