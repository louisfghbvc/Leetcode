// Observe end points is adjacent

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // goal: find the maximum score, and minimum score
        // idea:
        // the order can not change
        // must put in k bags, each bag is non-empty
        // cost a[l:r] are only arr[l]+arr[r]
        
        // dp: O(n^2k)
        // dfs(i, k):
        //  for j ~ n
        //    res = max(res, arr[i]+arr[j] + dfs(j+1, k-1));
        
        // greedy idea:
        // minimum only happen in 
        // (1) | (3,5,1)
        // (1,3) | (5,1)
        // (1,3,5) | (1)
        // when split, always add adjacent values
        
        int n = weights.size();
        vector<int> scores;
        for (int i = 1; i < n; ++i)
            scores.push_back(weights[i] + weights[i-1]);
        sort(scores.begin(), scores.end());

        long res = 0;
        int m = scores.size();
        for (int i = 0; i < k-1; ++i) {
            res -= scores[i];
            res += scores[m-i-1];
        }
        return res;
    }
};
