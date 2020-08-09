// O(N). Banlance.
// when left < 0, add it. because right always can't make left > 0
// finally remember add left. 
class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, res = 0;
        for(auto &c: S){
            if(c == '(') left++;
            else left--;
            if(left < 0) res++, left++;
        }
        return res + left;
    }
};
