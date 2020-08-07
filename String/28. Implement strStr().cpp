// O(N) kmp.
// lps build longest second pre-suf.
// so lps is when find same ++.
// not same. jump to prev same pos. until
// and find it.
// when find return begin.
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if(!n) return 0;
        vector<int> lps(n);
        for(int j = 1, i = 0; j < n; ++j){
            while(i > 0 && needle[i] != needle[j]) i = lps[i-1]; 
            if(needle[i] == needle[j]) lps[j] = ++i;
        }
        int i = 0;
        for(int j = 0; j < haystack.size(); ++j){
            while(i > 0 && needle[i] != haystack[j]) i = lps[i-1];
            if(needle[i] == haystack[j]) ++i;
            if(i == n) return j-n+1;
        }
        return -1;
    }
};

// Wait BT. AC
// WTF
// O(NM)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        for(int i = 0; i <= m-n; ++i){
            int j;
            for(j = 0; j < n; ++j){
                if(haystack[i+j] != needle[j]) break;
            }
            if(j == needle.size()) return i;
        }
        return -1;
    }
};
