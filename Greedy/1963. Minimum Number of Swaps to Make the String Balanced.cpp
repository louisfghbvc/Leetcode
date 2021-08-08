// O(N). Greedy. Observe that
// ]][[ -> 1.
// ]]][[[ -> 2.
// so just ceil(divide 2)
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int l = 0, r = 0;
        for(char c: s){
            if(c == ']'){
                if(l) l--;
                else r++;
            }
            else l++;
        }
        return (r+1)/2;
    }
};
