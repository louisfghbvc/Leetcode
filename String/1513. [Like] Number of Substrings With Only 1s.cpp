// O(N). Like Prefix dp
// Just Count and add it all. like 1D subarray.

class Solution {
public:
    int numSub(string s) {
        int mod = 1e9+7;
        int len = 0, res = 0;;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1'){
                len++;
            }
            else{
                len = 0;
            }
            res = (res+len)%mod;
        }
        return res;
    }
};
