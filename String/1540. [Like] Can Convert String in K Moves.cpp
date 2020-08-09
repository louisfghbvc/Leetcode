// O(N).
// because the diff is in 26. so use a array to record.
// and diff + 26*(fre[diff]-1) never overlap, because 0 + 26, 1 + 26....
// stick with it.
// just check if now diff + 26*(fre[diff]-1) > k.
// QQ
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.size(), m = t.size();
        if(n != m) return false;
        int fre[26] = {};
        for(int i = 0; i < n; ++i){
            if(s[i] == t[i]) continue;
            int tmp;
            if(s[i] < t[i]) tmp = t[i]-s[i];
            else tmp = t[i]+26 - s[i];
            fre[tmp]++;
            if(tmp + 26*(fre[tmp]-1) > k) return false;
        }
        return true;
    }
};
