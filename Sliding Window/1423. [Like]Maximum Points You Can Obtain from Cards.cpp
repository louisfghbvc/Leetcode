// Not optimal. Suffix. O(N), Space O(N)
// Prefix is same.
// Can just two var. 
// Just sliding left to right.
// 232ms 44.2MB
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> suf(n+1, 0);
        for(int i = n-1; i >= 0; --i){
            suf[i] += suf[i+1] + cardPoints[i];
        }
        int mx = suf[n-k], sum = 0;
        for(int i = 0; i < k; ++i){
            sum += cardPoints[i];
            mx = max(mx, suf[n-k+i+1] + sum);
        }
        return mx;
    }
};
