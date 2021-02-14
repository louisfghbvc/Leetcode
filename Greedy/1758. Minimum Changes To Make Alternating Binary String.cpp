// O(N). Greedy. == only two possible.

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string a = "", b = "";
        for(int i = 0, f = 0; i < n; ++i, f ^= 1) a += f+'0';
        for(int i = 0, f = 1; i < n; ++i, f ^= 1) b += f+'0';
        int n1 = 0, n2 = 0;
        for(int i = 0; i < n; ++i){
            n1 += a[i] != s[i];
            n2 += b[i] != s[i];
        }
        return min(n1, n2);
    }
};
