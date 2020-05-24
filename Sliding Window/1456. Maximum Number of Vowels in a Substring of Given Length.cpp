// Simple. sliding window with length k.
class Solution {
public:
    bool vowel(char c){
        return c == 'a' || c == 'e' || c=='i' || c == 'o' || c == 'u'; 
    }
    int maxVowels(string s, int k) {
        int mx = 0, cnt = 0;
        for(int l = 0, r = 0; r < s.size(); ++r){
            if(r - l + 1 > k){
                if(vowel(s[l])) cnt--;
                l++;
            }
            if(vowel(s[r])) cnt++;
            if(r - l + 1 == k) mx = max(cnt, mx);
        }
        return mx;
    }
};
