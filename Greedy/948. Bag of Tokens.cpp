// Intuition. O(NlogN)
// sort from small to big. and just use rule.
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0, mx = 0;
        int l = 0, r = n-1;
        while(l <= r){
            if(P >= tokens[l]) score++, P -= tokens[l++];
            else{
                if(score > 0) score--, P += tokens[r--];
                else break;
            }
            mx = max(mx, score);
        }
        return mx;
    }
};
