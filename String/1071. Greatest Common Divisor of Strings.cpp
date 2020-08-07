// KMP. Find smallest base.
// and then use that base calculate gcd.
// and return ans
// O(N)
class Solution {
public:
    int lps(string &s){
        int n = s.size();
        vector<int> A(n);
        for(int j = 1, i = 0; j < n; ++j){
            while(i > 0 && s[i] != s[j]) i = A[i-1];
            if(s[i] == s[j]) A[j] = ++i;
        }
        return A[n-1];
    }
    string gcdOfStrings(string str1, string str2) {
        int s1 = str1.size() - lps(str1);
        int s2 = str2.size() - lps(str2);
        string ls1 = str1.substr(0, s1);
        string ls2 = str2.substr(0, s2);
        if(ls1 != ls2) return "";
        int g = __gcd(str1.size()/s1, str2.size()/s2);
        return str1.substr(0, g*ls1.size());
    }
};

// solution 2 can use BF
// try every divisor % len == 0. prefix.

// solution 3 Super smart.
// so the main idea is if str1+str2 != str2+str1, means if change order no gcd.
// because if have gcd must s = gcd + gcd ...., no matter change position must have gcd.
// and each compose of some gcd string.
// O(N).
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return str1 + str2 != str2 + str1 ? "" 
            : str1.substr(0, __gcd(str1.size(), str2.size()));
    }
};
