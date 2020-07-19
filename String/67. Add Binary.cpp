// Can not reverse, but reverse is simple.

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max((int)a.size(), (int)b.size());
        int carry = 0;
        for(int i = 0; i < n; ++i){
            int aa = 0, bb = 0;
            if(i < a.size()) aa = (a[i]-'0');
            if(i < b.size()) bb = (b[i]-'0');
            int c = aa + bb + carry;
            res.push_back((c%2)+'0');
            carry = (c >= 2) ? 1 : 0;
        }
        if(carry) res.push_back(carry+'0');
        reverse(res.begin(), res.end());
        return res;
    }
};
