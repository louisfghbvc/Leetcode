// O(N^2). Use rolling prefix.
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            int fre[26] = {};
            auto check = [&](){
                for(int p = 0; p < 26; ++p) if(fre[p] && fre[p] < k) return false;
                return true;
            };
            for(int j = i; j < n; ++j){
                fre[s[j]-'a']++;
                if(check()) res = max(res, j-i+1);
            }
        }
        return res;
    }
};

// O(N). Tricky. how to determine nouse window. if just k, hard to determine.
// add feature. say distinct char. so enum all distinct char. so that just that distinct and at least k. maintain that window.
class Solution {
public:
    int helper(string &s, int k, int diff){
        int fre[26] = {};
        int l = 0, curDiff = 0, num = 0;
        int res = 0;
        for(int r = 0; r < s.size(); ++r){
            if(fre[s[r]-'a']++ == 0) curDiff++;
            while(curDiff > diff && l <= r){
                if(--fre[s[l]-'a'] == 0) curDiff--;
                if(fre[s[l++]-'a'] == k-1) num--;
            }
            if(fre[s[r]-'a'] == k) num++;
            if(num == curDiff) res = max(res, r-l+1);
        }
        return res;
    }
    int longestSubstring(string s, int k) {
        int res = 0;
        for(int d = 1; d <= 26; ++d)
            res = max(res, helper(s, k, d));
        return res;
    }
};
