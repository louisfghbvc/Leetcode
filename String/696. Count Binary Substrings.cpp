// O(N). Grouping string.

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, pre = 0, cur = 1;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == s[i-1]) cur++;
            else{
                res += min(pre, cur);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(pre, cur);
    }
};

// O(N). Two pointer.
class Solution {
public:
    int countBinarySubstrings(string s) {
        int zero = 0, one = 0;
        int res = 0;
        for(int i = 0, j = i; i < s.size(); i = j){
            j = i;
            if(s[j] == '0'){
                while(j < s.size() && s[j] == '0'){
                    if(one){
                        one--;
                        res++;
                    }
                    zero++;
                    j++;
                }
                one = 0;
            }
            else{
                while(j < s.size() && s[j] == '1'){
                    if(zero){
                        zero--;
                        res++;
                    }
                    one++;
                    j++;
                }
                zero = 0;
            }
        }
        return res;
    }
};
