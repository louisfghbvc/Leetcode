//O(N), Prefix sum.
// left part is zeroSum, right part is oneSum.
class Solution {
public:
    int maxScore(string s) {
        int oneSum = 0;
        for(auto &c : s) if(c == '1') oneSum++;
        
        int mx = 0, zeroSum = 0;
        for(int i = 0; i < s.size()-1; ++i){
            if(s[i] == '0') zeroSum++;
            else oneSum--;
            mx = max(mx, zeroSum + oneSum);
        }
        return mx;
    }
};
