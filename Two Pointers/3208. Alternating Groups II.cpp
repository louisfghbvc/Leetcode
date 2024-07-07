class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // goal: find the number of alternating group with length is k
        
        // idea:
        // TC: O(nk), 
        
        //. n=5
        //. 0 1 2
        //. l
        //      r
        // [0,1,0,1,0 0,1,0,1,0]
        //   T T T T F
        
        int n = colors.size();
        colors.insert(colors.end(), colors.begin(), colors.end());
        
        int cnt = 0;
        int ans = 0;
        for (int i = 1; i < 2*n; ++i) {
            cnt += colors[i] != colors[i-1];
            if (i >= k) {
                cnt -= colors[i-k+1] != colors[i-k];
            }
            if (i-k+1 < n)
                ans += cnt == k-1;
        }
        return ans;
    }
};
