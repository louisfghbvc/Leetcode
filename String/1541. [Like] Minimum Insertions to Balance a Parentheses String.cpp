// Just Case thinking.
// O(N).
// so if not two consecutive right, add a right. and left-1
// else left-1
// if left < 0, add a left.
// finally if has left, add left*2 right. 
// Very Simple right? QQ
class Solution {
public:
    int minInsertions(string s) {
        int res = 0, n = s.size();
        int left = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                left++;
            }
            else{
                if(i == n-1 || s[i+1] != ')'){
                    res++;
                }
                else{
                    i++;
                }
                left--;
            }
            if(left < 0){
                res++;
                left++;
            }
        }
        return res + 2*left;
    }
};
