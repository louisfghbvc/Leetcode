// use a param as stack in-out.
// so just a simple classic problem.
// O(N).

class Solution {
public:
    int maxDepth(string s) {
        int dep = 0;
        int res = 0;
        for(char c: s){
            if(c == '(') dep++;
            else if(c == ')') dep--;
            res = max(res, dep);
        }
        return res;
    }
};
