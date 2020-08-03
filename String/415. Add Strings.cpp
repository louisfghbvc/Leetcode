// Very Simple bigInteger add.
// O(N).

class Solution {
public:
    string addStrings(string n1, string n2) {
        string res;
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        int n = n1.size(), m = n2.size();
        int carry = 0;
        for(int i = 0, j = 0; i < n || j < m;){
            int sum = carry + (i<n ? n1[i++]-'0' : 0) + (j<m ? n2[j++]-'0' : 0);
            res.push_back(sum%10 + '0');
            carry = sum / 10;
        }
        if(carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
